## Proposed updates:   

- Support networks with `PMF` enabled.
- Associate each IP with a user. For instance, if we have a home network, then each IP is asigned to a distinct user without changes (most of the time). We can create a database and map MAC addresses to usernames. (Basic [CRUD](https://en.wikipedia.org/wiki/Create,_read,_update_and_delete) functionalities can be used here. We'll use a simple CSV file as database system.)

## Critical implementations awaiting:   

- Reveal all the connected clients to user. Right now, we only support up to 10 clients. This is an interface issue and does not relate to the actual functionality. The program is able to get the full list of connected clients flawlessly.
- Create a thread when a user selects a device to spoof, that sends automatically poisoned ARP replys to target every `X` seconds. This thread will stop when the user sets the target state back to normal (unspoof). An alternative solution would be to deauth the target using monitor mode. 
