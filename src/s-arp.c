#include "s-arp.h"

/**
 * User exit the program only with ctrl+c.
 * This functions is used as handler to clear
 * the memmory block from dynamic allocated 
 * structures.
 */
void exitGarbageCollector(int param);

/**
 * Static global structures. 
 * We put it here cause we need to
 * free it on exit in exitGarbageCollector().
 */
static netDevices *devicesListHead = NULL; 
static wirelessInterfaceMonitor WIMonitor;

int main(void) {
  signal(SIGINT, exitGarbageCollector); /* Catch ctrl+c signal. */

  initscr(); /* Start ncurses mode. */
  noecho(); /* Don't echo() characters passed with getch(). */
  curs_set(0); /* Make the cursor invisible. */
  printWelcomeScreen();

  wirelessInterface WI; 
  getWI(&WI); /* Get informations about the wireless interface we use. */

  addWIMonitor(&WIMonitor, "wimon0", WI.MAC); /* Create a wireless interface in monitor mode. */

  generateDevicesList(&devicesListHead, &WI); /* Associate every LAN address to an imaginary device. */

  pcapPrepareARPHandler(WI.deviceName); /* Prepare the pcap handler to process ARP data. */
  pcapSetARPHandlerFilter(WI.MAC, WI.subnetMask); /* Read only arp requests & reponses. */

  pcapPrepareDeauthHandler(WIMonitor.deviceName); /* Prepare the pcap handler to process deauth data.  */

  printARPLoadingScreen();
  startARPRequests(&devicesListHead, &WI);
  getARPResponses(&devicesListHead);

  int numberOfActiveDevices;
  getNumberOfActiveDevices(&numberOfActiveDevices, &devicesListHead);
 
  halfdelay(10); /* Used as timeout for user input. */

  /**
   * Bellow, starts the main program loop. 
   */
  while (1) {
    clear(); /* Clear completely the ncurses window. */
    drawTimeHeader();
    printActiveDevices(&devicesListHead);
    refresh(); /* Dump the written contents on the physical terminal screen. */

    /**
     * Ask user if he wants to take an action in the current repeat.
     * A pressed key indicates what the user want to do so.
     * If none key is pressed (here halfdelay() is used for), we step to the next repeat. 
     */
    int choice;
    choice = getch();
    if (choice == 'r') { /* Rescan the LAN. */
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
    pcapCloseARPHandler(); /* We can exit pcap capture procedure. */
  }
  if (devicesListHead != NULL) {
    clearDevicesList(&devicesListHead); /* Free the netDevices list. */
  }
  delWIMonitor(&WIMonitor); /* Delete wireless interface in monitor mode. */
  endwin(); /* Exit ncurses mode. */
  exit(EXIT_SUCCESS); /* Exit program. */
}
