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
qmk compile -kb ferris/sweep -km christnil
## for elite pi
qmk compile -kb ferris/sweep -km christnil   -e CONVERT_TO=elite_pi
```

### Flash
```sh
qmk flash -kb ferris/sweep -km christnil
```

for elite pi the compile will create a .uf2 file
enter boot mode on the unit and the n drag and drop the uf2 file to the drive, this will reboat and flash it
