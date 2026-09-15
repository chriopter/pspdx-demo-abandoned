#!/bin/sh
# Zips the built EBOOT as PSP/GAME/PSPDXAbandoned/, the layout a Memory Stick
# and PPSSPP expect. Writes dist/pspdx-demo-abandoned.zip and its sha256.
set -e
cd "$(dirname "$0")/.."
[ -f app/EBOOT.PBP ] || { echo "build first: make -C app" >&2; exit 1; }
rm -rf dist && mkdir -p dist/PSP/GAME/PSPDXAbandoned
cp app/EBOOT.PBP dist/PSP/GAME/PSPDXAbandoned/
cp LICENSE dist/PSP/GAME/PSPDXAbandoned/LICENSE.txt
(cd dist && zip -q -r -X pspdx-demo-abandoned.zip PSP)
rm -rf dist/PSP
sha256sum dist/pspdx-demo-abandoned.zip | tee dist/pspdx-demo-abandoned.zip.sha256
