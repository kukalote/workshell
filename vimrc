
" 设置前缀命令
let mapleader = ","

" 设置变量
let $SELFHOME="/usr/local/workshell/vim"
let $php_path="/usr/bin/php"
let $python_path="/usr/bin/python3"

" 引入当前目录下的vim配置
source $SELFHOME/sets.vim

" 引入当前目录下的vim插件配置
source $SELFHOME/plug.vim

" 命令及快捷键调整
source $SELFHOME/key_command.vim

" 折叠方案
source $SELFHOME/fold.vim

" 测试文件
source $SELFHOME/test.vim
