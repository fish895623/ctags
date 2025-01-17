/*
 * Generated by ./misc/optlib2c from optlib/kconfig.ctags, Don't edit this manually.
 */
#include "general.h"
#include "parse.h"
#include "routines.h"
#include "field.h"
#include "xtag.h"


typedef enum {
	K_CONFIG,
	K_MENU,
	K_MAINMENU,
	K_KCONFIG,
	K_CHOICE,
} KconfigKind;


static void initializeKconfigParser (const langType language CTAGS_ATTR_UNUSED)
{
}

extern parserDefinition* KconfigParser (void)
{
	static const char *const extensions [] = {
		NULL
	};

	static const char *const aliases [] = {
		NULL
	};

	static const char *const patterns [] = {
		"Kconfig*",
		NULL
	};

	static roleDefinition KconfigKconfigRoleTable [] = {
		{ true, "source", "kconfig file loaded with source directive" },
	};
	static kindDefinition KconfigKindTable [] = {
		{
		  true, 'c', "config", "configs",
		},
		{
		  true, 'm', "menu", "menus",
		},
		{
		  true, 'M', "mainMenu", "the main menu",
		},
		{
		  true, 'k', "kconfig", "kconfig file",
		  ATTACH_ROLES(KconfigKconfigRoleTable),
		},
		{
		  true, 'C', "choice", "choices",
		},
	};
	static xtagDefinition KconfigXtagTable [] = {
		{
		  .enabled     = true,
		  .name        = "configPrefixed",
		  .description = "prepend CONFIG_ to config names",
		},
	};
	static tagRegexTable KconfigTagRegexTable [] = {
		{"^[ \t]*#.*$", "",
		"", "{placeholder}", NULL, false},
		{"^[ \t]*(menu)?config[ \t]+([A-Za-z0-9_]+)[ \t]*$", "\\2",
		"c", "{scope=ref}", NULL, false},
		{"^[ \t]*(menu)?config[ \t]+([A-Za-z0-9_]+)[ \t]*$", "CONFIG_\\2",
		"c", "{scope=ref}{_extra=configPrefixed}", NULL, false},
		{"^[ \t]*(menu)?config[ \t]+([A-Za-z0-9_]+)[ \t]*$", "CONFIG_\\2_MODULE",
		"c", "{scope=ref}{_extra=configPrefixed}{exclusive}", NULL, false},
		{"^[ \t]*menu[ \t]+\"([^\"]+)\"[ \t]*", "\\1",
		"m", "{scope=push}{exclusive}", NULL, false},
		{"^[ \t]*endmenu[ \t]*", "",
		"", "{scope=pop}{placeholder}{exclusive}", NULL, false},
		{"^[ \t]*source[ \t]+\"?([^\"]+)\"?[ \t]*", "\\1",
		"k", "{_role=source}{exclusive}{scope=ref}", NULL, false},
		{"^[ \t]*choice[ \t]+([A-Za-z0-9_]+)[ \t]*", "\\1",
		"C", "{scope=push}{exclusive}", NULL, false},
		{"^[ \t]*choice[ \t]*$", "",
		"C", "{_anonymous=choice}{scope=push}{exclusive}", NULL, false},
		{"^[ \t]*endchoice[ \t]*", "",
		"", "{scope=pop}{placeholder}{exclusive}", NULL, false},
		{"^[ \t]*mainmenu[ \t]+\"([^\"]+)\"[ \t]*", "\\1",
		"M", "{exclusive}", NULL, false},
	};


	parserDefinition* const def = parserNew ("Kconfig");

	def->versionCurrent= 0;
	def->versionAge    = 0;
	def->enabled       = true;
	def->extensions    = extensions;
	def->patterns      = patterns;
	def->aliases       = aliases;
	def->method        = METHOD_NOT_CRAFTED|METHOD_REGEX;
	def->useCork       = CORK_QUEUE;
	def->kindTable     = KconfigKindTable;
	def->kindCount     = ARRAY_SIZE(KconfigKindTable);
	def->xtagTable     = KconfigXtagTable;
	def->xtagCount     = ARRAY_SIZE(KconfigXtagTable);
	def->tagRegexTable = KconfigTagRegexTable;
	def->tagRegexCount = ARRAY_SIZE(KconfigTagRegexTable);
	def->defaultScopeSeparator = "\"\"";
	def->initialize    = initializeKconfigParser;

	return def;
}
