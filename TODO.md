##Proposed updates:   
---
- Support networks with `PMF` enabled.
- Associate each ip with a user. For instance, if we have a home network, then it's true that every member of uses the connection daily. We can create a database and map MAC address with a username and reveal it to the user interface of our program. (Basic [CRUD](https://en.wikipedia.org/wiki/Create,_read,_update_and_delete) module is needed here. We'll use text file as database system.)

##Critical implementations awaiting:   
---
- Add a method to support all showing clients for spoofing. Now we only can support up to 10, in best case scenario.
- Create a thread when a user selects a device to spoof, that sends automatically poisoned ARP replys to target every `X` seconds. This thread will stop when the user sets the target's state back to normal (unspoof).

