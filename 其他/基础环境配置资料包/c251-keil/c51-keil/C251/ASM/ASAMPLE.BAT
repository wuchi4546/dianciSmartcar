REM This Batch-File generates a Sample-Program for the A251-Assembler
a251 asample1.a51 debug xref
a251 asample2.a51 debug xref
a251 asample3.a51 debug xref
l251 asample1.obj,asample2.obj,asample3.obj to asample ixref
oh251 asample
