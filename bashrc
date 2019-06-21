
# 配置
export EDITOR=vim

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8


export nginxlog='/var/log/nginx'
export nginxconf='/etc/nginx/conf.d'
export vimss='/var/vimsession/'
export uxinwork='/var/www/uxin_sites/'
export testwork='/var/www/test/'
export selfwork='/usr/local/workshell/'
export snip='/usr/local/workshell/vim/bundle/vim-snippets/UltiSnips/php.snippets'
#export SELFSERVERS='/usr/local/share/servers'

export PATH="$PATH:$selfwork/command"



PROMPT='%{$fg_bold[red]%}➜ %{$fg_bold[green]%}%p%{$fg[cyan]%}%d %{$fg_bold[blue]%}$(git_prompt_info)%{$fg_bold[blue]%}% %{$reset_color%}' 
#PROMPT='${ret_status} %{$fg[cyan]%}%d%{$reset_color%} $(git_prompt_info)$ '


# zshell powerline 主题配置
#{
    # 主题wiki https://github.com/bhilburn/powerlevel9k
#    source /usr/lib/powerlevel9k/powerlevel9k.zsh-theme

    # 时间格式配置
    #POWERLEVEL9K_TIME_FORMAT='%D{%H:%M:%S}'
    #左标,右标信息
    #POWERLEVEL9K_LEFT_PROMPT_ELEMENTS=(context dir rbenv vcs)
#    POWERLEVEL9K_RIGHT_PROMPT_ELEMENTS=(status  history time)
#}


# 命令别名创建
alias cls='clear'
alias synctime='sudo ntpdate pool.ntp.org'
alias dirls="printf '%s\r\n' \$(\dirs) | awk '{print NR-1\"\t\"\$0}'"
alias datefm="echo '======================';date '+%Y-%m-%d %T';echo '======================';cal -3 -m"

###########################
#引入外部文件
source $selfwork/bash/func.sh
source $selfwork/bash/services.sh
source $selfwork/bash/go.sh


##########################
# 关掉selinux
setenforce 0 2>/dev/null

# 命令行以 vim 模式操作
#set -o vi



# 启动服务
which nginx >/dev/null
if [ $? -eq 0 ] 
then
    which systemctl >/dev/null
    if [ $? -eq 0 ] 
    then
        sudo -S systemctl start nginx
    fi
fi

which php>/dev/null
if [ $? -eq 0 ] 
then
    which systemctl >/dev/null
    if [ $? -eq 0 ] 
    then
        sudo -S systemctl start php-fpm
    fi
fi

which mysqld>/dev/null
if [ $? -eq 0 ] 
then
    which systemctl >/dev/null
    if [ $? -eq 0 ] 
    then
        sudo -S isCentOS && systemctl start mysqld
    fi
fi

which redis-server>/dev/null
if [ $? -eq 0 ] 
then
    which systemctl >/dev/null
    if [ $? -eq 0 ] 
    then
        sudo -S systemctl start redis-server
    fi
fi
