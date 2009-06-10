# ~/.profile: executed by the command interpreter for login shells.

# the default umask is set in /etc/profile; for setting the umask
# for ssh logins, install and configure the libpam-umask package.
#umask 022

# if running bash
if [ -n "$BASH_VERSION" ]; then
    # include .bashrc if it exists
    if [ -f "$HOME/.bashrc" ]; then
	. "$HOME/.bashrc"
    fi
fi

# set PATH so it includes user's private bin if it exists
if [ -d "$HOME/bin" ] ; then
    PATH="$HOME/bin:$PATH"
fi

#export SYSTEM_OSX='Mac OS X'
#export SYSTEM_TIGER='Mac OS X 10.4'
#export SYSTEM_LEOPARD='Mac OS X 10.5'
#export SYSTEM_NIX='Linux'

export SYSTEM_OSX='darwin9.0'
export SYSTEM_LINUX='linux-gnu'

if [[ $OS_TYPE =~ $SYSTEM_OSX ]]; then
  export EDITOR='mate'
                        # causes issues with crontab -e
  export VISUAL='mate -w'
  export SVN_EDITOR='mate -w'
  export GIT_EDITOR='mate -w'
elif [[ $OS_TYPE =~ $SYSTEM_LINUX ]]; then
  export EDITOR='vim'
  export VISUAL='vim'
else
  export EDITOR='vi'
  export VISUAL='vi'
fi


if [[ $OS_TYPE =~ $SYSTEM_OSX ]]; then
  export JAVA_HOME=/System/Library/Frameworks/JavaVM.framework/Versions/1.5/Home
  #export JAVA_HOME=/usr/local/soylatte
fi

export JRUBY_HOME=/usr/local/jruby
export ANT_HOME=/usr/bin/ant
export M2_HOME=/usr/local/maven
export CATALINA_HOME=/usr/local/tomcat
export GRAILS_HOME=$HOME/Dev/grails
export ROO_HOME=$HOME/Dev/roo

PATH=$HOME/bin:$GRAILS_HOME/bin:/usr/local/bin:/opt/local/bin:/opt/local/sbin:$JAVA_HOME/bin:$PATH:$JRUBY_HOME/bin:/usr/local/mysql/bin:/opt/local/lib/postgresql83/bin:/usr/local/php5/bin:$HOME/Dev/depot_tools
export PATH

if [ -f ~/.profile_private ]; then
  . ~/.profile_private
fi

# For DataObjects / DataMapper TESTING
#export DO_MYSQL_SPEC_URI="mysql://root:$MYSQL_ROOT_PASS@localhost/do_mysql_test?socket=/var/mysql/mysql.sock"
#export DO_MYSQL_SPEC_JDBC_URI="jdbc:mysql://localhost:3306/do_mysql_test?user=root&password=$MYSQL_ROOT_PASS"

#export MYSQL_SPEC_URI="mysql://root@localhost/dm_core_test"
export POSTGRES_SPEC_URI="postgres://postgres:$MYSQL_ROOT_PASS@192.168.0.10/dm_core_test"
#export SQLITE3_SPEC_URI="sqlite3://primary.db"

alias netbeans-jdk6="/Applications/NetBeans/NetBeans\ 6.1.app/Contents/MacOS/netbeans --jdkhome /usr/local/soylatte/ --laf javax.swing.plaf.metal.MetalLookAndFeel"
