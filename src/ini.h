// todo(rayalan): documentation
#ifndef INI_INCLUDE
#define INI_INCLUDE
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef INI_MAX_STRING_LENGTH
#define INI_MAX_STRING_LENGTH 256
#endif

	typedef enum Ini_Error {
		INI_ERROR_NONE = 0,
		INI_ERROR_ASSIGNMENT,
		INI_ERROR_SECTION,
		INI_ERROR_LENGTH,
		INI_ERROR_CALLBACK,
		INI_ERROR_COUNT
	} Ini_Error;

	typedef struct Ini_Parse_Result {
		Ini_Error error;
		int line;
	} Ini_Parse_Result;

	typedef int Ini_Callback(char const *section, char const *name, char const *value);
	Ini_Parse_Result ini_parse(char *src, Ini_Callback* callback);

	const char *ini_error_string(Ini_Error error);
	extern const char *INI_ERROR_LIST[INI_ERROR_COUNT];

#ifdef INI_IMPLEMENTATION

	const char *INI_ERROR_LIST[INI_ERROR_COUNT] = {
		"",
		"Error at or near assignment",
		"Incomplete section",
		"Exceded maximum length of section, name, or value",
		"Error in callback",
	};

	const char *ini_error_string(Ini_Error error) {
		return INI_ERROR_LIST[error];
	}

	// TODO(rayalan): TESTS
	Ini_Parse_Result ini_parse(char *src, Ini_Callback* callback) {
		char section[INI_MAX_STRING_LENGTH] = { 0 };
		char name[INI_MAX_STRING_LENGTH] = { 0 };
		char value[INI_MAX_STRING_LENGTH] = { 0 };
		int line = 1;
		char *c = src;

		// Don't crash opening a UTF-8 file
		if (((unsigned char)c[0] == 0xef) &&
			((unsigned char)c[1] == 0xbb) &&
			((unsigned char)c[2] == 0xbf)) {
			c += 3;
		}

		while (*c != '\0') {
			if ((*c == ';') || (*c == '#')) {
				while (*c != '\n') {
					if (*c == '\0') { return { INI_ERROR_NONE, line }; }
					c++;
				}
			}
			else if ((*c != '\t') && (*c != ' ') && (*c != '\r') && (*c != '\n')) { // 
				if (*c == '[') { // section
					int i = 0;
					c++;
					while (*c != ']') {
						if (i == INI_MAX_STRING_LENGTH) { return { INI_ERROR_LENGTH, line }; }
						if ((*c == '\n') || (*c == '\0')) { return { INI_ERROR_SECTION, line }; }
						section[i] = *c;
						i++; c++;
					}
					section[i] = '\0';
					c++;
					// we past ]
					while ((*c != '\n') && (*c != '\0')) {
						c++;
					}
				}
				else { // this is a name/value pair
					int i = 0;
					while ((*c != '=') && (*c != ':')) {
						if (i == INI_MAX_STRING_LENGTH) { return { INI_ERROR_LENGTH, line }; }
						if ((*c == '\n') || (*c == '\0')) { return { INI_ERROR_ASSIGNMENT, line }; }
						name[i] = *c;
						i++; c++;
					}
					name[i - 1] = '\0';
					c++;
					while ((*c == '\t') || (*c == ' ')) { c++; }
					if ((*c == '\n') || (*c == '\0')) { return { INI_ERROR_ASSIGNMENT, line }; }
					int j = 0;
					while ((*c != '\n') && (*c != '\r') && (*c != '\0')) {
						if (j == INI_MAX_STRING_LENGTH) { return { INI_ERROR_LENGTH, line }; }
						value[j] = *c;
						j++; c++;
					}
					value[j] = '\0';
					if (!callback(section, name, value)) {
						return { INI_ERROR_CALLBACK, line };
					}
				}
			}
			if (*c == '\n') {
				line++;
			}
			c++;
		}
		return { INI_ERROR_NONE, line };
	}

#endif /* INI_IMPLEMENTATION */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* INI_INCLUDE */