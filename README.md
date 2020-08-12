### Coinicles

#### Cico is an open sourced public blockchain platform, which combines the security of Bitcoin UTXO while enabling multiple virtual machines including EVM and the revolutionary x86 VM. Cico is now PoS based and boasts a Decentralized Governance Protocol (DGP) allowing specific blockchain settings to be modified by making use of cico smart contracts. For instance, the block size of CICO just like qtum can be increased without the need of a hard fork. With 

|   Spec.          | Value  | 
| ------------ | ------------- | 
| Ticker       |     CICO         |
| Total supply |     100million   |
| P2P          |     38880         | 
| RPC          |     38890         | 
| Stake Reward |     12.8          |
| Confirmation |     500 blocks    |
| Staking Methods | Offline & Online |


[Explorer](https://explorer.coinicles.tech)

# Building Cico Core

### Validate and Reproduce Binaries

Cico uses a tool called Gitian to make reproducible builds that can be verified by anyone. Instructions on setting up a Gitian VM and building Cico are provided in [Gitan Building](https://github.com/coinicles/cico/blob/master/doc/gitian-building.md)

### Build on Ubuntu

This is a quick start script for compiling Cico on Ubuntu


    sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils git cmake libboost-all-dev libgmp3-dev
    sudo apt-get install software-properties-common
    sudo add-apt-repository ppa:bitcoin/bitcoin
    sudo apt-get update
    sudo apt-get install libdb4.8-dev libdb4.8++-dev

    # If you want to build the Qt GUI:
    sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler qrencode

    git clone https://github.com/coinicles/cico --recursive
    cd cico

    # Note autogen will prompt to install some more dependencies if needed
    ./autogen.sh
    ./configure 
    make -j2
    
### Build on CentOS

Here is a brief description for compiling Cico on CentOS, for more details please refer to [the specific document](https://github.com/coinicles/cico/blob/master/doc/build-unix.md)

    # Compiling boost manually
    sudo yum install python-devel bzip2-devel
    git clone https://github.com/boostorg/boost.git
    cd boost
    git checkout boost-1.66.0
    git submodule update --init --recursive
    ./bootstrap.sh --prefix=/usr --libdir=/usr/lib64
    ./b2 headers
    sudo ./b2 -j4 install
    
    # Installing Dependencies for Cico
    sudo yum install epel-release
    sudo yum install libtool libdb4-cxx-devel openssl-devel libevent-devel gmp-devel
    
    # If you want to build the Qt GUI:
    sudo yum install qt5-qttools-devel protobuf-devel qrencode-devel
    
    # Building Cico
    git clone --recursive https://github.com/coinicles/cico.git
    cd cico
    ./autogen.sh
    ./configure
    make -j4

### Build on Mac OS

The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.

#### Preparation

Install the Mac OS command line tools:

`xcode-select --install`

When the popup appears, click `Install`.

Then install [Homebrew](https://brew.sh).

#### Dependencies

    brew install cmake automake berkeley-db4 libtool boost miniupnpc openssl pkg-config protobuf qt5 libevent imagemagick librsvg qrencode gmp

NOTE: Building with Qt4 is still supported, however, could result in a broken UI. Building with Qt5 is recommended.

#### Build Cico Core

1. Clone the cico source code and cd into `cico`

        git clone --recursive https://github.com/coinicles/cico.git
        cd cico

2.  Build cico-core:

    Configure and build the headless cico binaries as well as the GUI (if Qt is found).

    You can disable the GUI build by passing `--without-gui` to configure.

        ./autogen.sh
        ./configure
        make

3.  It is recommended to build and run the unit tests:

        make check

### Run

Then you can either run the command-line daemon using `src/cicod` and `src/cico-cli`, or you can run the Qt GUI using `src/qt/cico-qt`

License
-------

Cico is GPLv3 licensed.


Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/coinicles/cico/tags) are created
regularly to indicate new official, stable release versions of Cico.

The contribution workflow is described in [CONTRIBUTING.md](https://github.com/coinicles/cico/blob/master/CONTRIBUTING.md).


Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

