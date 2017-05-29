## The s-arp  project   
![](https://img.shields.io/badge/version-0.5-9B59B6.svg?style=flat-square) ![](https://img.shields.io/badge/license-GPLv3-1E8BC3.svg?style=flat-square)
#### An ARP spoofing tool for your LAN.
----------

## System Requirements

This tool was developed under Ubuntu 16.04. Other flavors of Linux might be able to run it, but it wasn't tested.

## How to install

#### Depedencies

You need to have `libpcap` and `ncurses` packages installed on your system to successfully `make` the project. To install the packages run:

    apt-get install libpcap-dev libncurses-dev

#### Compile

To install this program you have to redirect to the project's folder and run:

    make && make install

#### Execute

To execute the program simply type in your terminal:

    s-arp

## Project tree

Some important files and folders that are used in this project are explained bellow:

 -  `TODO.md`: Contains suggestions for future versions.    
 -  `BugHunter.md`: Contains all known bugs.
 - `src`: Here is the main source code of the program.

## Issues

For new ideas, bugs, improvements or any question about this project don't hesitate to create a new issue.

## Maintenance

I tried to write a self documented code. Nevertheless, there may be some parts that need explanations. You can always contact me in my personal email at `georgegkas@gmail.com` if you wish.

## License
`s-arp` is copyrighted to George G. Gkasdrogkas under [GNU GPLv3](https://www.gnu.org/licenses/gpl-3.0.en.html) license.
