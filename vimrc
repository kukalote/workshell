" 查看 vim 加载信息
" vim --startuptime vimloading
" 设置前缀命令
let mapleader = ","
" 设置变量
let $SELFHOME="/root/workshell/vim"
let $php_path="/usr/bin/php"
let $python_path="/usr/bin/python"
let $python3_path="/usr/bin/python3"

" 引入当前目录下的vim插件配置
source $SELFHOME/plug.vim

" 命令及快捷键调整
source $SELFHOME/key_command.vim

" 折叠方案
source $SELFHOME/fold.vim

" 引入当前目录下的vim配置,防止上面加载有其他操作覆盖
source $SELFHOME/sets.vim

" 测试文件
source $SELFHOME/test.vim
