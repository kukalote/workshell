"function! Komment()
"    if getline(".") =~ '\/\*'
"        let hls=@/
"        s/^\/\*//
"        s/*\/$//
"        let @/=hls
"    else
"        let hls=@/
"        s/^/\/*/
"        s/$/*\//
"        let @/=hls
"    endif
"endfunction
"map <leader>k :call Komment()<CR>
