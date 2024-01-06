# QMK Userspace

An [external QMK userspace][external-userspace] for maintaining my own keymaps and configuration files outside the main firmware repository.

## Compiling

Compile the firmware for a particular keyboard and keymap:

```shell
qmk compile -kb <keyboard> -km <keymap>
```

Compile all build targets, as defined in [`qmk.json`](./qmk.json):
```shell
qmk userspace-compile
```

## Management

Create a new keymap and add it to the build targets file:

```shell
qmk userspace-add -kb <your_keyboard> -km <your_keymap>
```

Remove a keymap:

```shell
qmk userspace-remove -kb <your_keyboard> -km <your_keymap>
```

Convert a C keymap to Configurator JSON:

```shell
qmk c2json -kb <your_keyboard> -km <your_keymap>
```

Convert Configurator export to a C keymap:

```shell
qmk json2c <your_export>
```

## Related

- [`filterpaper/qmk_userspace`][filterpaper-userspace]
- [`qmk/qmk_userspace`][qmk-userspace]

<!-- References -->

[external-userspace]: https://docs.qmk.fm/#/newbs_external_userspace
[filterpaper-userspace]: https://github.com/filterpaper/qmk_userspace
[qmk-userspace]: https://github.com/qmk/qmk_userspace
