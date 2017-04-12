# 关掉selinux
setenforce 0 2>/dev/null

# 启动服务
systemctl start nginx
systemctl start php-fpm
systemctl start mysql

# 配置
export EDITOR=vim

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8


export nginxlog='/var/log/nginx'
export nginxconf='/etc/nginx/conf.d'
export vimsession='/var/vimsession'
export uxinwork='/var/www/uxin_sites'
export testwork='/var/www/test'
export selfwork='/usr/local/workshell'



#PROMPT='%{$fg_bold[red]%}➜ %{$fg_bold[green]%}%p%{$fg[cyan]%}%d %{$fg_bold[blue]%}$(git_prompt_info)%{$fg_bold[blue]%}% %{$reset_color%}' 
#PROMPT='${ret_status} %{$fg[cyan]%}%d%{$reset_color%} $(git_prompt_info)$ '


# zshell powerline 主题配置
#{
    # 主题wiki https://github.com/bhilburn/powerlevel9k
    source /usr/lib/powerlevel9k/powerlevel9k.zsh-theme

    # 时间格式配置
    #POWERLEVEL9K_TIME_FORMAT='%D{%H:%M:%S}'
    #左标,右标信息
    #POWERLEVEL9K_LEFT_PROMPT_ELEMENTS=(context dir rbenv vcs)
    POWERLEVEL9K_RIGHT_PROMPT_ELEMENTS=(status  history time)
#}


# 命令别名创建
alias cls='clear'
alias synctime='sudo ntpdate pool.ntp.org'
alias gccact="gcc -o action $*"
alias dirs="dirs | tr ' ' '\n' | tac |  cat -n"

#引入外部文件
source $selfwork/bash/func.sh
