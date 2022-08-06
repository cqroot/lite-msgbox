# Lite MsgBox

A lite message box.

## Usage

```bash
lite-msgbox \
    -m "Message to display" \
    -b 'OK:1;Cancel:0' \
    -t 60
```

This will open an message box with buttons `OK` and `Cancel`.
When you click the `OK` button, the program will exit and return `0`;
when you click the `Cancel` button, the program will exit and return `1`.

## Custom appearance

```text
+---------------------------------------------------+
|                                                   |
|                QLabel#MessageLabel                |
|                                                   |
| |<-- QSpacerItem -->| |QPushButton| |QPushButton| |
+---------------------------------------------------+
```
