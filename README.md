# Lite MsgBox

A lite message box.

## Usage

```bash
lite-msgbox \
    --message "Message to display" \
    --buttons 'OK:1;Cancel:2' \
    --timeout 60
```

This will open an message box with buttons `OK` and `Cancel`.

- When you click the `OK` button, the program will exit and return `1`;
- When you click the `Cancel` button, the program will exit and return `2`;
- If you don't click any button in 60s, the program will exit and return `0`.

## Custom appearance

You can use `--qss` or `-s` to specify your qss file.
The default qss file is [qss/default.qss](https://github.com/cqroot/lite-msgbox/blob/main/qss/default.qss).

The layout of the dialog is as follows:

```text
+---------------------------------------------------+
| QLabel#TitleLabel                                 |
+---------------------------------------------------+
|                                                   |
|                QLabel#MessageLabel                |
|                                                   |
| |<-- QSpacerItem -->| |QPushButton| |QPushButton| |
+---------------------------------------------------+
```
