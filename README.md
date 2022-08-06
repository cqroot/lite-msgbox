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

```text
+---------------------------------------------------+
|                                                   |
|                QLabel#MessageLabel                |
|                                                   |
| |<-- QSpacerItem -->| |QPushButton| |QPushButton| |
+---------------------------------------------------+
```
