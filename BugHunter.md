## Bellow is a list of all known bugs-issues:   

- `s-arp` doesn't work on wireless networks with *Protected Managment Frames* enabled. ([read about PMF](https://www.cisco.com/c/en/us/td/docs/wireless/controller/technotes/5700/software/release/ios_xe_33/11rkw_DeploymentGuide/b_802point11rkw_deployment_guide_cisco_ios_xe_release33/b_802point11rkw_deployment_guide_cisco_ios_xe_release33_chapter_0100.pdf))   
    **Note:** PMF is described on [802.11w-2009](https://en.wikipedia.org/wiki/IEEE_802.11w-2009) standard. PMF can't be enabled on WLANs of `None`, `WEP` and `WPA` encryption. Thus `s-arp` can be used on that networks. `s-arp` can also be used on `WPA2` networks, if PMF is not enabled.
- There are cases that some clients will automatically request a new ARP from a device when they see that their arp table has changed. There are many softwares that prevent ARP spoofing.
- `s-arp` does not handle more that 10 clients for spoofing, even if they are available on user's screen. At worst case no more than 7, which is also the average one. This happens beacause the user has to select the number of the target in his keyboard to be able to spoof him. We don't capture two-digit numbers so the available devices that are able to spoof is with serial number 0 through 9. 
- `s-arp` **has been tested and work on the following cases:** 
	- Android  <= 4.4.2
	  **Notes:** 
		1.  If a target running Android is spoofed, he can easily get back his internet connection if he disable and re-enable his WIFI. We can apply (i) to bypass the problem. 
-  The unspoof functionality sometimes does not work.
