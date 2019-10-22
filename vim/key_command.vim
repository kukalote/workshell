""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""快捷键-命令""""""""""""""""""""""""""""""""""""""""""
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" 自动加载vimrc, 无需重启gvim
"autocmd! bufwritepost _vimrc source %
"autocmd BufWritePost $MYVIMRC source $MYVIMRC
" 编辑配置文件
map <silent> <leader>em :e $SELFHOME<CR>:noh<cr>

" 加载配置文件 
map <silent> <leader>lm :source $SELFHOME/../vimrc<CR>:noh<CR>

" 窗口跳转
nmap <C-k> <C-W>k
nmap <C-h> <C-W>h
nmap <C-j> <C-W>j
nmap <C-l> <C-W>l

" tab 间跳转
nmap <silent> <leader>1 1gt
nmap <silent> <leader>2 2gt
nmap <silent> <leader>3 3gt
nmap <silent> <leader>4 4gt
nmap <silent> <leader>5 5gt
" tab 创建
nmap <silent> <leader>nt :tabnew<CR>

" 隐藏/行号
nmap <silent> <leader>hn :set nu!<CR>:set relativenumber!<CR>
" 取消重点显示
nmap <silent> <leader>hh :noh<CR>
" 当前编辑窗口最大化
nmap <silent> <leader>ww :res 333<CR>:vertical res 333<CR>
" 当前编辑窗口最小化
nmap <silent> <leader>ws :res 1<CR>
nmap <silent> <leader>wv :vertical res 1<CR>

" 插入模式自动转换
"imap ex example



" lhs comments
map <leader># :s/^/#/<CR>:noh<CR>
map <leader>/ :s/^/\/\//<CR>:noh<CR>
map <leader>> :s/^/> /<CR>:noh<CR>
map <leader>" :s/^/\"/<CR>:noh<CR>
map <leader>% :s/^/%/<CR>:noh<CR>
map <leader>! :s/^/!/<CR>:noh<CR>
map <leader>; :s/^/;/<CR>:noh<CR>
map <leader>- :s/^/-- /<CR>:noh<CR>
map <leader>' :s/^["#;\/!-]*//<CR>:noh<CR>
map <leader>t A // MY todo<Esc>:noh<CR>
map <leader>r :s/\s\/\/\sMY\stodo//g<CR>:noh<CR>
"map ,c :s/^\/\/\\|^--\\|^> \\|^[#"%!;]//<CR>:noh<CR>

" wrapping comments
map <leader>* :'<,'>s/^\(.*\)$/\/\* \1 \*\//<CR>:noh<CR>
"map <leader>( :s/^\(.*\)$/\(\* \1 \*\)/<CR>:noh<CR>
map <leader>< :s/^\(.*\)$/<!-- \1 -->/<CR>:noh<CR>
"map ,d :s/^\([/(]\*\\|<!--\) \(.*\) \(\*[/)]\\|-->\)$/\2/<CR>:noh<CR>

"
" 添加php调试输出, var_dump('a');exit;
nmap <silent> <leader>var ovar_dump('a');exit;<Esc>:w<CR>4blvh%h
vmap <silent> <leader>vv  yOvar_dump('a');exit;<Esc>4blvh%hp:w<CR>

" 格式化括号
nmap <silent> <leader>( :%s/(\s/(/g<CR>:%s/\s)/)/g<CR>
nmap <silent> <leader>if :%s/if(/if (/g<CR>
":%s/for(/for (/g<CR>:noh<CR>:%s/foreach(/foreach (/g<CR>:%s/}else/} else/g<CR>:%s/else{/else {/g<CR>

" 重定义:E命令
cabbrev E Explore
cabbrev mkss mksession! $vimss/
iabbrev funcdes  /**<CR>*<CR>* @author xunyalong<CR>*/<Esc><Left><C-v>%=<Down>A 
"iabbrev var var_dump();



