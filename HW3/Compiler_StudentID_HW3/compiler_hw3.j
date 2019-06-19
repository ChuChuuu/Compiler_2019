.class public compiler_hw3
.super java/lang/Object
.method public static try(I)I
.limit stack 50
.limit locals 50
	ldc 20
	istore 1
	iload 1
	ldc 40
	i2f
	swap
	i2f
	swap
	fcmpl
	ifne LABEL_IF_FALSE_1
	ldc "a is equal to 40"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto LABEL_IF_EXIT_1
LABEL_IF_FALSE_1:
	iload 1
	ldc 40
	i2f
	swap
	i2f
	swap
	fcmpl
	ifle LABEL_IF_FALSE_2
	ldc "a is larger than 40"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto LABEL_IF_EXIT_2
LABEL_IF_FALSE_2:
	ldc 666
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
LABEL_IF_EXIT_2:
LABEL_IF_EXIT_1:
	ldc "--------------"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	iload 1
	ldc 20
	i2f
	swap
	i2f
	swap
	fcmpl
	ifle LABEL_IF_FALSE_3
	ldc 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
goto LABEL_IF_EXIT_3
LABEL_IF_FALSE_3:
	iload 1
	ldc 30
	i2f
	swap
	i2f
	swap
	fcmpl
	ifle LABEL_IF_FALSE_4
	ldc 2
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
goto LABEL_IF_EXIT_4
LABEL_IF_FALSE_4:
	ldc 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
LABEL_IF_EXIT_4:
	iload 1
	ldc 20
	i2f
	swap
	i2f
	swap
	swap
	fcmpl
	ifle LABEL_IF_FALSE_5
	ldc 4
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
LABEL_IF_FALSE_5:
LABEL_IF_EXIT_3:
	ldc "-------------"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	iload 1
	ldc 20
	i2f
	swap
	i2f
	swap
	fcmpl
	ifne LABEL_IF_FALSE_6
	iload 1
	ldc 20
	i2f
	swap
	i2f
	swap
	fcmpl
	ifeq LABEL_IF_FALSE_7
	ldc 6
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
goto LABEL_IF_EXIT_7
LABEL_IF_FALSE_7:
	iload 1
	ldc 20
	i2f
	swap
	i2f
	swap
	fcmpl
	ifne LABEL_IF_FALSE_8
	ldc 7
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 1
	ldc 20
	i2f
	swap
	i2f
	swap
	fcmpl
	ifeq LABEL_IF_FALSE_9
	ldc 10
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
goto LABEL_IF_EXIT_9
LABEL_IF_FALSE_9:
	ldc 11
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc 0
	istore 2
LABEL_WHILE_BEGIN_1:
	iload 2
	ldc 10
	i2f
	swap
	i2f
	swap
	swap
	fcmpl
	ifle LABEL_WHILE_FALSE_1
	iload 2
	ldc 2
	irem
	istore 3
	iload 3
	ldc 0
	i2f
	swap
	i2f
	swap
	fcmpl
	ifne LABEL_IF_FALSE_10
	ldc "even"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	iload 2
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
goto LABEL_IF_EXIT_10
LABEL_IF_FALSE_10:
	ldc "odd"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	iload 2
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
LABEL_IF_EXIT_10:
	iload 2
	ldc 1
	iadd
	istore 2
	goto LABEL_WHILE_BEGIN_1
LABEL_WHILE_FALSE_1:
LABEL_IF_EXIT_9:
goto LABEL_IF_EXIT_8
LABEL_IF_FALSE_8:
	ldc 8
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
LABEL_IF_EXIT_8:
	iload 1
	ldc 20
	i2f
	swap
	i2f
	swap
	fcmpl
	ifeq LABEL_IF_FALSE_11
	ldc 9
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
goto LABEL_IF_EXIT_11
LABEL_IF_FALSE_11:
	ldc 12
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
LABEL_IF_EXIT_11:
LABEL_IF_EXIT_7:
goto LABEL_IF_EXIT_6
LABEL_IF_FALSE_6:
	ldc "nohere"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
LABEL_IF_EXIT_6:
	iload 0
	ldc 10
	i2f
	swap
	i2f
	swap
	fcmpl
	ifle LABEL_IF_FALSE_12
	ldc ">10return0"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 0
	ireturn
goto LABEL_IF_EXIT_12
LABEL_IF_FALSE_12:
	iload 0
	ldc 5
	i2f
	swap
	i2f
	swap
	swap
	fcmpl
	ifle LABEL_IF_FALSE_13
	ldc "<5return1"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 1
	ireturn
goto LABEL_IF_EXIT_13
LABEL_IF_FALSE_13:
	ldc ">5<=10return2"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 2
	ireturn
LABEL_IF_EXIT_13:
LABEL_IF_EXIT_12:
	ldc 7
	ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 2
	istore 0
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 0
	invokestatic compiler_hw3/try(I)I
	istore 0
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
