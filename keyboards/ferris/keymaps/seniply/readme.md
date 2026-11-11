copied from: https://github.com/benvallack/34-QMK-Ferris-Sweep/

## BOOT
### Install QMK
```sh
brew install qmk/qmk/qmk
```

### Setup QMK
```sh
qmk setup
```

### Compile
```sh
qmk compile -kb ferris/sweep -km seniply
```

### Flash
```sh
qmk flash -kb ferris/sweep -km seniply
```
