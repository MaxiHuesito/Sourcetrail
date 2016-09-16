#ifndef JAVA_PARSER_H
#define JAVA_PARSER_H

#include <map>
#include <mutex>

#include "data/parser/Parser.h"
#include "data/parser/java/JavaEnvironment.h"
#include "utility/logging/logging.h"

struct JNIEnv_;
typedef JNIEnv_ JNIEnv;

class _jobject;
typedef _jobject* jobject;

#ifdef _WIN32
typedef long jint;
#else
typedef int jint;
#endif

class _jstring;
typedef _jstring *jstring;

class FileRegister;

class JavaParser: public Parser
{
public:
	JavaParser(ParserClient* client);
	~JavaParser();

	// ParserClient implementation
	virtual void parseFiles(const std::vector<FilePath>& filePaths, const Arguments& arguments);
	virtual void parseFile(const FilePath& filePath, std::shared_ptr<TextAccess> textAccess, const Arguments& arguments);


private:

// This macro makes available a variable T, the passed-in t. blablabla TODO: write somethign real here
#define MAKE_PARAMS_0()
#define MAKE_PARAMS_1(t1) t1 arg1
#define MAKE_PARAMS_2(t1, t2) t1 arg1, t2 arg2
#define MAKE_PARAMS_3(t1, t2, t3) t1 arg1, t2 arg2, t3 arg3
#define MAKE_PARAMS_4(t1, t2, t3, t4) t1 arg1, t2 arg2, t3 arg3, t4 arg4
#define MAKE_PARAMS_5(t1, t2, t3, t4, t5) t1 arg1, t2 arg2, t3 arg3, t4 arg4, t5 arg5
#define MAKE_PARAMS_6(t1, t2, t3, t4, t5, t6) t1 arg1, t2 arg2, t3 arg3, t4 arg4, t5 arg5, t6 arg6
#define MAKE_PARAMS_7(t1, t2, t3, t4, t5, t6, t7) t1 arg1, t2 arg2, t3 arg3, t4 arg4, t5 arg5, t6 arg6, t7 arg7
#define MAKE_PARAMS_8(t1, t2, t3, t4, t5, t6, t7, t8) t1 arg1, t2 arg2, t3 arg3, t4 arg4, t5 arg5, t6 arg6, t7 arg7, t8 arg8
#define MAKE_PARAMS_9(t1, t2, t3, t4, t5, t6, t7, t8, t9) t1 arg1, t2 arg2, t3 arg3, t4 arg4, t5 arg5, t6 arg6, t7 arg7, t8 arg8, t9 arg9
#define MAKE_PARAMS_10(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) t1 arg1, t2 arg2, t3 arg3, t4 arg4, t5 arg5, t6 arg6, t7 arg7, t8 arg8, t9 arg9, t10 arg10
#define MAKE_PARAMS_11(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) t1 arg1, t2 arg2, t3 arg3, t4 arg4, t5 arg5, t6 arg6, t7 arg7, t8 arg8, t9 arg9, t10 arg10, t11 arg11
#define MAKE_PARAMS_12(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12) t1 arg1, t2 arg2, t3 arg3, t4 arg4, t5 arg5, t6 arg6, t7 arg7, t8 arg8, t9 arg9, t10 arg10, t11 arg11, t12 arg12
//.. add as many MAKE_PARAMS_* as required

#define MAKE_ARGS_0()
#define MAKE_ARGS_1(type) arg1
#define MAKE_ARGS_2(t1, t2) arg1, arg2
#define MAKE_ARGS_3(t1, t2, t3) arg1, arg2, arg3
#define MAKE_ARGS_4(t1, t2, t3, t4) arg1, arg2, arg3, arg4
#define MAKE_ARGS_5(t1, t2, t3, t4, t5) arg1, arg2, arg3, arg4, arg5
#define MAKE_ARGS_6(t1, t2, t3, t4, t5, t6) arg1, arg2, arg3, arg4, arg5, arg6
#define MAKE_ARGS_7(t1, t2, t3, t4, t5, t6, t7) arg1, arg2, arg3, arg4, arg5, arg6, arg7
#define MAKE_ARGS_8(t1, t2, t3, t4, t5, t6, t7, t8) arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8
#define MAKE_ARGS_9(t1, t2, t3, t4, t5, t6, t7, t8, t9) arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9
#define MAKE_ARGS_10(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10
#define MAKE_ARGS_11(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11
#define MAKE_ARGS_12(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12) arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12
//.. add as many MAKE_ARGS_* as there are MAKE_PARAMS_*



#define DEF_RELAYING_METHOD_4(NAME, t1, t2, t3, t4)										\
	DEF_RELAYING_METHOD(NAME, MAKE_PARAMS_4(t1, t2, t3, t4), MAKE_ARGS_4(t1, t2, t3, t4))

#define DEF_RELAYING_METHOD_5(NAME, t1, t2, t3, t4, t5)									\
	DEF_RELAYING_METHOD(NAME, MAKE_PARAMS_5(t1, t2, t3, t4, t5), MAKE_ARGS_5(t1, t2, t3, t4, t5))

#define DEF_RELAYING_METHOD_6(NAME, t1, t2, t3, t4, t5, t6)								\
	DEF_RELAYING_METHOD(NAME, MAKE_PARAMS_6(t1, t2, t3, t4, t5, t6), MAKE_ARGS_6(t1, t2, t3, t4, t5, t6))

#define DEF_RELAYING_METHOD_7(NAME, t1, t2, t3, t4, t5, t6, t7)							\
	DEF_RELAYING_METHOD(NAME, MAKE_PARAMS_7(t1, t2, t3, t4, t5, t6, t7), MAKE_ARGS_7(t1, t2, t3, t4, t5, t6, t7))

#define DEF_RELAYING_METHOD_8(NAME, t1, t2, t3, t4, t5, t6, t7, t8)						\
	DEF_RELAYING_METHOD(NAME, MAKE_PARAMS_8(t1, t2, t3, t4, t5, t6, t7, t8), MAKE_ARGS_8(t1, t2, t3, t4, t5, t6, t7, t8))

#define DEF_RELAYING_METHOD_9(NAME, t1, t2, t3, t4, t5, t6, t7, t8, t9)					\
	DEF_RELAYING_METHOD(NAME, MAKE_PARAMS_9(t1, t2, t3, t4, t5, t6, t7, t8, t9), MAKE_ARGS_9(t1, t2, t3, t4, t5, t6, t7, t8, t9))

#define DEF_RELAYING_METHOD_10(NAME, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10)			\
	DEF_RELAYING_METHOD(NAME, MAKE_PARAMS_10(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10), MAKE_ARGS_10(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10))

#define DEF_RELAYING_METHOD_11(NAME, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11)		\
	DEF_RELAYING_METHOD(NAME, MAKE_PARAMS_11(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11), MAKE_ARGS_11(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11))

#define DEF_RELAYING_METHOD_12(NAME, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12)	\
	DEF_RELAYING_METHOD(NAME, MAKE_PARAMS_12(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12), MAKE_ARGS_12(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12))

#define DEF_RELAYING_METHOD(NAME, PARAMETERS, ARGUMENTS)								\
	static void NAME(JNIEnv *env, jobject objectOrClass, jint parserId, PARAMETERS)		\
	{																					\
		std::map<int, JavaParser*>::iterator it = s_parsers.find(int(parserId));		\
		if (it != s_parsers.end())														\
		{																				\
			it->second->do##NAME(ARGUMENTS);											\
		}																				\
		else																			\
		{																				\
			LOG_ERROR("parser with id " + std::to_string(parserId) + " not found");		\
		}																				\
	}

	DEF_RELAYING_METHOD_8(RecordSymbol, jstring, jint, jint, jint, jint, jint, jint, jint)
	DEF_RELAYING_METHOD_4(RecordSymbolWithoutLocation, jstring, jint, jint, jint)
	DEF_RELAYING_METHOD_12(RecordSymbolWithScope, jstring, jint, jint, jint, jint, jint, jint, jint, jint, jint, jint, jint)
	DEF_RELAYING_METHOD_7(RecordReference, jint, jstring, jstring, jint, jint, jint, jint)
	DEF_RELAYING_METHOD_5(RecordLocalSymbol, jstring, jint, jint, jint, jint)
	DEF_RELAYING_METHOD_4(RecordComment, jint, jint, jint, jint)
	DEF_RELAYING_METHOD_7(RecordError, jstring, jint, jint, jint, jint, jint, jint)

	static int s_nextParserId;
	static std::map<int, JavaParser*> s_parsers;
	static std::mutex s_parsersMutex;






	void doRecordSymbol(
		jstring jSymbolName, jint jSymbolType,
		jint beginLine, jint beginColumn, jint endLine, jint endColumn,
		jint jAccess, jint jIsImplicit
	);

	void doRecordSymbolWithoutLocation(
		jstring jSymbolName, jint jSymbolType,
		jint jAccess, jint jIsImplicit
	);

	void doRecordSymbolWithScope(
		jstring jSymbolName, jint jSymbolType,
		jint beginLine, jint beginColumn, jint endLine, jint endColumn,
		jint scopeBeginLine, jint scopeBeginColumn, jint scopeEndLine, jint scopeEndColumn,
		jint jAccess, jint jIsImplicit
	);

	void doRecordReference(jint jRefType, jstring jReferencedName, jstring jContextName, jint beginLine, jint beginColumn, jint endLine, jint endColumn);
	void doRecordLocalSymbol(jstring jSymbolName, jint beginLine, jint beginColumn, jint endLine, jint endColumn);
	void doRecordComment(jint beginLine, jint beginColumn, jint endLine, jint endColumn);
	void doRecordError(jstring jMessage, jint jFatal, jint jIndexed, jint beginLine, jint beginColumn, jint endLine, jint endColumn);

	std::shared_ptr<FileRegister> m_fileRegister;
	std::shared_ptr<JavaEnvironment> m_javaEnvironment;

	const int m_id;
	std::string m_currentFilePath;
};

#endif // JAVA_PARSER_H