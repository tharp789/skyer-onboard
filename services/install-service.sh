#!/bin/bash

# Install script for skyer-onboard systemd service

set -e

SERVICE_NAME="skyer-onboard"
SERVICE_FILE="skyer-onboard.service"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Check if running as root
if [ "$EUID" -ne 0 ]; then
    echo "Please run as root (sudo ./install-service.sh)"
    exit 1
fi

# Copy service file to systemd directory
echo "Installing systemd service..."
cp "$SCRIPT_DIR/$SERVICE_FILE" /etc/systemd/system/

# Reload systemd daemon
echo "Reloading systemd daemon..."
systemctl daemon-reload

# Enable the service to start on boot
echo "Enabling $SERVICE_NAME service..."
systemctl enable $SERVICE_NAME

echo ""
echo "Installation complete!"
echo ""
echo "Commands:"
echo "  Start now:      sudo systemctl start $SERVICE_NAME"
echo "  Stop:           sudo systemctl stop $SERVICE_NAME"
echo "  Check status:   sudo systemctl status $SERVICE_NAME"
echo "  View logs:      sudo journalctl -u $SERVICE_NAME -f"
echo "  Disable:        sudo systemctl disable $SERVICE_NAME"
echo ""
echo "Note: Edit /etc/systemd/system/$SERVICE_FILE to change STORAGE_PATH if needed."
