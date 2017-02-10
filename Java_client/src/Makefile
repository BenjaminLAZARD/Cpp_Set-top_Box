##########################################
#
#To run the java program
#
##########################################

#
# Nom du programme (doit correspondre au fichier qui contient main())
#
PROG = MainFrame

#
# Fichiers sources .java
#
SOURCES = QuitMenuItem.java  Remote.java MainFrame.java

#
# Compilateur Java
#
JC = javac

#
# Options du compilateur Java
#
JFLAGS = -g


##########################################
#
# Regles de construction/destruction des .class et de l'executable
#

all: classes

run: all
	java ${PROG}

classes: $(SOURCES:.java=.class)

clean:
	-@$(RM) *.class 1>/dev/null 2>&1

tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}


###########################################
#
# Regles implicites
#

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java
