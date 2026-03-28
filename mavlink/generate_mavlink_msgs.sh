#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

XML_PATH="${XML_PATH:-${SCRIPT_DIR}/mission_msgs.xml}"
OUTPUT_DIR_C="${OUTPUT_DIR_C:-${SCRIPT_DIR}/builds}"
OUTPUT_DIR_JS="${OUTPUT_DIR_JS:-${SCRIPT_DIR}/builds/js}"

mkdir -p "$OUTPUT_DIR_C" "$OUTPUT_DIR_JS"

python3 -m pymavlink.tools.mavgen \
  --lang=C \
  --wire-protocol=2.0 \
  --output "$OUTPUT_DIR_C" \
  "$XML_PATH"

python3 -m pymavlink.tools.mavgen \
  --lang=javascript \
  --wire-protocol=2.0 \
  --output "$OUTPUT_DIR_JS" \
  "$XML_PATH"
