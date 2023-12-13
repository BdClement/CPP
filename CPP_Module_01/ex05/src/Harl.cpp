// snippets class
// {
//     	"Class Declaration": {
// 			"prefix": "classmodele",
// 			"body": [
// 				"class ${1:nomADefinir}",
// 				"{",
// 				"    public:",
// 				"    // Méthodes de la classe",
// 				"    $1();",
// 				"    ~$1();",
// 				"",
// 				"    private:",
// 				"    // Attributs membres de la classe",
// 				"",
// 				"};"
// 			],
// 			"description": "Template for a C++ class declaration"
// 		}
// }


// Snippets Makefile
	// {
	// 	"Custom Makefile": {
	// 		"prefix": "makefile",
	// 		"body": [
	// 			"## MAIN VARIABLES",
	// 			"",
	// 			"NAME = \t\t\t",
	// 			"",
	// 			"CC = \t\t\tc++",
	// 			"",
	// 			"CFLAGS = \t\t-Wall -Wextra -Werror -std=c++98",
	// 			"",
	// 			"RM =\t\t\trm -f",
	// 			"",
	// 			"RM_RF =\t\t\trm -rf",
	// 			"",
	// 			"## SOURCES AND LIBS",
	// 			"",
	// 			"SRC_DIR = \t\t./src",
	// 			"",
	// 			"SRCS =\t\t\t${SRC_DIR}/",
	// 			"",
	// 			"## OBJECTS",
	// 			"",
	// 			"OBJ_DIR =\t\t./obj",
	// 			"",
	// 			"OBJS = \t\t\t${patsubst ${SRC_DIR}/%.cpp, ${OBJ_DIR}/%.o, ${SRCS}}",
	// 			"",
	// 			"## HEADERS",
	// 			"",
	// 			"HDIR = \t\t\t./inc",
	// 			"",
	// 			"HD = \t\t\t${HDIR}/",
	// 			"",
	// 			"INC_HD =\t\t-I ${HDIR}",
	// 			"",
	// 			"## RULES",
	// 			"",
	// 			"all:\t\t\t${NAME}",
	// 			"",
	// 			"${NAME}:\t\t${OBJS}",
	// 			"\t\t\t\t${CC} ${CFLAGS} ${INC_HD} ${OBJS} -o $@",
	// 			"",
	// 			"${OBJS}:\t\t${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${HD}",
	// 			"\t\t\t\tmkdir -p ${OBJ_DIR}",
	// 			"\t\t\t\t${CC} ${CFLAGS} ${INC_HD} -c $< -o $@",
	// 			"",
	// 			"clean:",
	// 			"\t\t\t\t${RM_RF} ${OBJ_DIR}",
	// 			"",
	// 			"fclean:\t\t\tclean",
	// 			"\t\t\t\t${RM} ${NAME}",
	// 			"",
	// 			"re:\t\t\t\tfclean all",
	// 			"",
	// 			".PHONY:\t\t\tall clean fclean re"
	// 		],
	// 		"description": "Custom Makefile Template"
	// 	}
	// }
