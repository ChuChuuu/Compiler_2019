.class public compiler_hw3
.super java/lang/Object
.field public static A I = 0
.field public static B I = 2
.field public static D F = 2.000000
.field public static H I = 1
.field public static I I = 0
.method public static foo1()I
.limit stack 50
.limit locals 50
	ldc 2
	ireturn
.end method
.method public static foo2()F
.limit stack 50
.limit locals 50
	ldc 2.000000
	freturn
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	getstatic compiler_hw3/A I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	getstatic compiler_hw3/B I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	getstatic compiler_hw3/D F
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	ldc 0
	istore 0
	ldc 2
	istore 1
	ldc 2.000000
	f2i
	istore 2
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 2
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc 0
	i2f
	fstore 3
	ldc 2
	i2f
	fstore 4
	ldc 2.000000
	fstore 5
	fload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	fload 4
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	fload 5
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	ldc "test"
	astore 6
	aload 6
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 1
	istore 7
	ldc 0
	istore 8
	ldc 1
	iload 0
	iadd
	istore 9
	ldc 1
	fload 3
	swap
	i2f
	swap
	fadd
	f2i
	istore 10
	iload 1
	ldc 2.000000
	swap
	i2f
	swap
	fadd
	f2i
	istore 11
	fload 4
	ldc 2.000000
	fadd
	f2i
	istore 12
	iload 9
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 10
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 11
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 12
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	invokestatic compiler_hw3/foo1()I
	istore 13
	ldc 1
	invokestatic compiler_hw3/foo1()I
	iadd
	istore 14
	invokestatic compiler_hw3/foo1()I
	ldc 1.000000
	swap
	i2f
	swap
	fsub
	f2i
	istore 15
	iload 13
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 14
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 15
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc 1.000000
	fload 3
	fadd
	fstore 16
	ldc 1.000000
	iload 0
	i2f
	fadd
	fstore 17
	fload 4
	ldc 1
	i2f
	fadd
	fstore 18
	iload 1
	ldc 1
	iadd
	i2f
	fstore 19
	fload 16
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	fload 17
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	fload 18
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	fload 19
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	invokestatic compiler_hw3/foo2()F
	fstore 20
	ldc 1.000000
	invokestatic compiler_hw3/foo2()F
	fadd
	fstore 21
	invokestatic compiler_hw3/foo2()F
	ldc 1
	i2f
	fsub
	fstore 22
	invokestatic compiler_hw3/foo2()F
	fload 20
	swap
	fadd
	fstore 20
	fload 20
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	fload 21
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	fload 22
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	return
.end method
