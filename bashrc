# 关掉selinux
setenforce 0 2>/dev/null

# 启动服务
systemctl start nginx
systemctl start php-fpm
systemctl start mysql

# 配置
export GREP_OPTIONS='--color=auto'
export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8


export lognginx='/var/log/nginx'
export confnginx='/etc/nginx/conf.d'
export vimsession='/var/vimsession'
export mywork='/var/www'
export uxinwork='/var/www/uxin_sites'
export testwork='/var/www/test'
export selfwork=~/workshell



#PROMPT='%{$fg_bold[red]%}➜ %{$fg_bold[green]%}%p%{$fg[cyan]%}%d %{$fg_bold[blue]%}$(git_prompt_info)%{$fg_bold[blue]%}% %{$reset_color%}' 
PROMPT='${ret_status} %{$fg[cyan]%}%d%{$reset_color%} $(git_prompt_info)$ '

# 命令别名创建
alias cls='clear'
alias synctime='sudo ntpdate pool.ntp.org'
source $selfwork/bash/func.sh
