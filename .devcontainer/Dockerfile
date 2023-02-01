FROM ghcr.io/armmbed/mbed-os-env:latest

ARG USERNAME=husarion
ARG USER_UID=1000
ARG USER_GID=$USER_UID
USER ${username}

SHELL ["/bin/bash", "-c"]

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    #
    # [Optional] Add sudo support. Omit if you don't need to install software after connecting.
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# ********************************************************
# * Anything else you want to do like clean up goes here *
# ********************************************************

# [Optional] Set the default user. Omit if you want to keep the default as root.

USER $USERNAME

RUN sudo apt-get update \
    && sudo apt-get install -y \
    libusb-1.0 \
    stlink-tools \
    libncurses5 \
    && sudo rm -rf /var/lib/apt/lists/*

CMD [ "bash" ]