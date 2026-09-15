# PSPDX Abandoned Demo

A tiny PSP hello-world that plays an abandoned homebrew: it has releases but
no `.pspdx`. The [PSPDX Catalog](https://github.com/chriopter/pspdx-catalog)
lists it anyway, from a file in its `listed/` folder, and marks the entry with
`listed_by`. See the [PSPDX standard](https://chriopter.github.io/pspdx/).

## What's in here

- `app/` → the app
- `tools/package.sh` → packs the ZIP
- `.github/workflows/psp.yml` → builds the release
