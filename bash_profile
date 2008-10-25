#PS1='\[\e[0;32m\]\u\[\e[m\] \[\e[1;34m\]\w\[\e[m\] \[\e[1;32m\]\$ \[\e[m\]\[\e[1;37m\] '

# source .bashrc if it's there
if [ -f ~/.bashrc ]; then
    . ~/.bashrc
fi

export SYSTEM_OSX='Mac OS X'
export SYSTEM_TIGER='Mac OS X 10.4'
export SYSTEM_LEOPARD='Mac OS X 10.5'
export SYSTEM_NIX='Linux'

if [[ $SYSTEM =~ $SYSTEM_OSX ]]; then
  export EDITOR='mate'
                        # causes issues with crontab -e 
  export VISUAL='mate -w'
  export SVN_EDITOR='mate -w'
  export GIT_EDITOR='mate -w'
elif [[ $SYSTEM =~ $SYSTEM_NIX ]]; then
  export EDITOR='nano'
  export VISUAL='nano'
else
  export EDITOR='vi'
  export VISUAL='vi'
fi

#export JAVA_HOME=/System/Library/Frameworks/JavaVM.framework/Versions/1.5/Home
export JAVA_HOME=/usr/local/soylatte
export JRUBY_HOME=/usr/local/jruby
export ANT_HOME=/usr/bin/ant
export M2_HOME=/usr/local/maven
export CATALINA_HOME=/usr/local/tomcat
export GRAILS_HOME=$HOME/Dev/grails

PATH=$HOME/bin:$GRAILS_HOME/bin:/usr/local/bin:/opt/local/bin:/opt/local/sbin:$JAVA_HOME/bin:$PATH:$JRUBY_HOME/bin:/usr/local/mysql/bin:/usr/local/php5/bin:$HOME/Dev/depot_tools
export PATH

if [ -f ~/.profile_private ]; then
  . ~/.profile_private
fi

# For DataObjects / DataMapper TESTING
export DO_MYSQL_SPEC_URI="mysql://root:$MYSQL_ROOT_PASS@localhost/do_mysql_test?socket=/var/mysql/mysql.sock"
export DO_MYSQL_SPEC_JDBC_URI="jdbc:mysql://localhost:3306/do_mysql_test?user=root&password=$MYSQL_ROOT_PASS"
export MYSQL_SPEC_URI="mysql://root:$MYSQL_ROOT_PASS@localhost/dm_core_test?socket=/var/mysql/mysql.sock"

alias netbeans-jdk6="/Applications/NetBeans/NetBeans\ 6.1.app/Contents/MacOS/netbeans --jdkhome /usr/local/soylatte/ --laf javax.swing.plaf.metal.MetalLookAndFeel"
