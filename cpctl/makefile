# executable files for this directory
OBJECTS = FolderMain HasPtrUseCount \
		  HasPtrValueLike copyNoMove \
		  moveHP serial StrFolderMain \
		  useStrVec substr 

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and  files
include ../GNU_makefile_template

LOCFLAGS = -I../1 -I../7

Folder.o FolderMain.o: Folder.h
StrFolder.o StrFolderMain.o: StrFolder.h String.h
String.o: String.h
useStrVec.o StrVec.o: String.h StrVec.h

useStrVec: StrVec.o useStrVec.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) StrVec.o useStrVec.o -o useStrVec

FolderMain: Folder.o FolderMain.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) Folder.o FolderMain.o -o FolderMain

StrFolderMain: StrFolder.o StrFolderMain.o String.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) StrFolder.o StrFolderMain.o String.o \
		-o StrFolderMain

