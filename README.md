## The s-arp  project   
![](https://img.shields.io/badge/version-0.5-9B59B6.svg?style=flat-square) ![](https://img.shields.io/badge/license-GPLv3-1E8BC3.svg?style=flat-square)
#### ARP spoofing for your LAN
----------

## System Requirements

This tool was developed under Ubuntu 16.04. Other flavors of Linux might be able to run it as well.

## How to install

#### Depedencies

You need to have `libpcap` and `ncurses` packages installed on your system to successfully `make` the project. To install the packages run as `sudo` user:

```bash
$ apt-get install libpcap-dev libncurses-dev
```

#### Compile

To install this program run:

```bash
path/to/project$ make && make install
```

#### Execute

To execute the program simply type in your terminal:

```bash
s-arp
```

## Project tree

Some important files and folders that are used in this project are explained bellow:

- `TODO.md`: Contains suggestions for future versions  
- `BugHunter.md`: Contains all known bugs
- `src`: The main source code of the program

## Maintenance

This project is not maintained anymore. In case you want to continue the development you can create a new issue and I will personally reach you.

## License
`s-arp` is licensed under [MIT](https://opensource.org/licenses/MIT).
