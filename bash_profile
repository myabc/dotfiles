#PS1='\[\e[0;32m\]\u\[\e[m\] \[\e[1;34m\]\w\[\e[m\] \[\e[1;32m\]\$ \[\e[m\]\[\e[1;37m\] '

# source .bashrc if it's there
if [ -f ~/.bashrc ]; then
		. ~/.bashrc
fi

PATH=$HOME/bin:/usr/local/php5/bin:/usr/local/bin:/opt/local/bin:/opt/local/sbin:$PATH:/usr/local/jruby/bin:/usr/local/mysql/bin

export ANT_HOME=/usr/bin/ant
export M2_HOME=/usr/local/maven
export CATALINA_HOME=/usr/local/tomcat
export EDITOR='mate -w'
export SVN_EDITOR='mate -w'
export GIT_EDITOR='mate -w'

export PATH
