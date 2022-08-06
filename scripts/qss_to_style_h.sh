#!/usr/bin/env bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

# {
#     echo '#ifndef LITE_MSGBOX_STYLE_H'
#     echo '#define LITE_MSGBOX_STYLE_H'
#     echo ''
#     echo '#include <QString>'
#     echo ''
#     echo 'QString DefaultStyle() {'
#     echo -n '    return'

#     IFS=''
#     while read -r line; do
#         echo
#         echo -n "        \"$line\""
#     done <"${SCRIPT_DIR}/../qss/default.qss"

#     echo ';'
#     echo '}'
#     echo
#     echo '#endif //LITE_MSGBOX_STYLE_H'

# } >"${SCRIPT_DIR}/../src/style.h"

{
    echo '#ifndef LITE_MSGBOX_STYLE_H'
    echo '#define LITE_MSGBOX_STYLE_H'
    echo ''
    echo '#include <QString>'
    echo ''
    echo 'QString DefaultStyle()'
    echo '{'
    echo -n '    return '

    FIRSTLINE=1
    IFS=''
    while read -r line; do
        if [ $FIRSTLINE -eq 1 ]; then
            FIRSTLINE=0
            echo -n "\"$line\""
        else
            echo ''
            echo -n "           \"$line\""
        fi
    done <"${SCRIPT_DIR}/../qss/default.qss"
    echo ';'

    echo '}'
    echo ''
    echo '#endif // LITE_MSGBOX_STYLE_H'
    echo ''
} >"${SCRIPT_DIR}/../src/style.h"
