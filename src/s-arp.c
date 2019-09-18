#include "s-arp.h"

/**
 * This is a handler function to clear
 * the memory block from dynamic allocated 
 * structures when user exist with ctrl+c.
 */
void exitGarbageCollector(int param);

/**
 * Static global structures used by exitGarbageCollector().
 */
static netDevices *devicesListHead = NULL; 
static wirelessInterfaceMonitor WIMonitor;

int main(void) {
  /**
   * Catch ctrl+c signal.
   */
  signal(SIGINT, exitGarbageCollector);

  /**
   * Start ncurses mode.
   */
  initscr();

  /**
   * Don't echo() characters passed with getch().
   */
  noecho();

  /**
   * Make the cursor invisible.
   */
  curs_set(0);

  printWelcomeScreen();

  /**
   * Get information about the wireless interface.
   */
  wirelessInterface WI; 
  getWI(&WI);

  /**
   * Create a wireless interface in monitor mode.
   */
  addWIMonitor(&WIMonitor, "wimon0", WI.MAC);

  /**
   * Associate every LAN address to an imaginary device.
   */
  generateDevicesList(&devicesListHead, &WI);

  /**
   * Prepare the pcap handler to process ARP data.
   */
  pcapPrepareARPHandler(WI.deviceName);

  /**
   * Read only arp requests and reponse.
   */
  pcapSetARPHandlerFilter(WI.MAC, WI.subnetMask);

  /**
   * Prepare the pcap handler to process deauth data.
   */
  pcapPrepareDeauthHandler(WIMonitor.deviceName);

  printARPLoadingScreen();
  startARPRequests(&devicesListHead, &WI);
  getARPResponses(&devicesListHead);

  int numberOfActiveDevices;
  getNumberOfActiveDevices(&numberOfActiveDevices, &devicesListHead);
 
  /**
   * Used as timeout for user input.
   */
  halfdelay(10);

  /**
   * Bellow, starts the main program loop. 
   */
  while (1) {
    /**
     * Clear completely the ncurses window.
     */
    clear();
    drawTimeHeader();
    printActiveDevices(&devicesListHead);

    /**
     * Dump the written contents on the physical terminal screen.
     */
    refresh();

    /**
     * Ask user if he wants to take an action in the current repeat.
     * A pressed key indicates what the user wants to do so.
     * If none key is pressed (halfdelay() is used), 
     * we step to the next repeat. 
     */
    int choice;
    choice = getch();
    if (choice == 'r') {
      /**
       * Rescan the LAN.
       */
      clear();
      printARPLoadingScreen();
      clearARPCache(&devicesListHead);
      startARPRequests(&devicesListHead, &WI);
      getARPResponses(&devicesListHead);
      getNumberOfActiveDevices(&numberOfActiveDevices, &devicesListHead);
    } else if (isChoiceInActiveDevices(choice, numberOfActiveDevices)) {
      /**
       * handleARPSpoof() is used as wrapper.
       * We have to know which is the device state (NORMAL or SPOOFED),
       * and get the opposite action. 
       */
      handleARPSpoof(&devicesListHead, &WI, choice);
    }
  }
}

void exitGarbageCollector(int param) {
  if (pcapARPHandler != NULL) {
    /**
     * We can exit pcap capture procedure. 
     */
    pcapCloseARPHandler();
  }
  if (devicesListHead != NULL) {
    /**
     * Free the netDevices list.
     */
    clearDevicesList(&devicesListHead);
  }

  /**
   * Delete wireless interface in monitor mode.
   */
  delWIMonitor(&WIMonitor);

  /**
   * Exit ncurses mode.
   */
  endwin();

  /**
   * Exit program.
   */
  exit(EXIT_SUCCESS);
}
