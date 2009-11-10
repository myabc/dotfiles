export CLICOLOR=1
# use yellow for directories
# export LSCOLORS=dxfxcxdxbxegedabagacad
# use cyan for directories
export LSCOLORS=gxfxcxdxbxegedabagacad

source ~/.git-completion.sh
PS1='[\u@\h \W$(__git_ps1 " (%s)")]\$ '
PS1="\$(~/.rvm/bin/binscripts/rvm-prompt)$PS1"

# rvm-install added line:
if [[ -s /usr/local/rvm/scripts/rvm ]] ; then source /usr/local/rvm/scripts/rvm ; fi

# -- start rip config -- #
RIPDIR=/Users/alexbcoles/.rip
RUBYLIB="$RUBYLIB:$RIPDIR/active/lib"
PATH="$PATH:$RIPDIR/active/bin"
export RIPDIR RUBYLIB PATH
# -- end rip config -- #
