#!/usr/bin/env bash
# Installs the heaptrack program on linux
# We have to build from source instead of installing via apt, since
# the apt version (1.3.0) doesn't allow specifying an output file

check_heaptrack_installed() {
    if ! command -v /usr/local/bin/heaptrack &> /dev/null
    then
        YELLOW='\033[0;33m' # colour for emphasis
        COLOR_OFF='\033[0m'

        echo "heaptrack is not yet installed"
        echo "Installing heaptrack. This may take a few minutes."
        echo -e "${YELLOW}ECE2071 Note: ${COLOR_OFF}You may be asked for your password, to allow your computer to install the memory management tools we need" 
        echo -e "For security, in the terminal window, ${YELLOW}you will not 'see' your password being entered${COLOR_OFF} as you type, but your keypresses will still be recorded fine."
        echo ""

        install_heaptrack
    fi
}

install_heaptrack() {
    # install dependencies needed for building
    sudo apt install -y cmake libunwind-dev libboost-iostreams-dev libboost-program-options-dev libzstd-dev libboost-system-dev libboost-filesystem-dev zlib1g-dev

    git clone https://github.com/KDE/heaptrack.git

    cd heaptrack/
    mkdir build
    cd build 
    cmake -DCMAKE_BUILD_TYPE=Release ..
    make -j$(nproc)
    sudo make install

    cd ../..
}