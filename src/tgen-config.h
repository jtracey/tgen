#ifndef TGEN_CONFIG_H_
#define TGEN_CONFIG_H_

#include <glib.h>

gint tgenconfig_gethostname(gchar* name, size_t len);
gchar* tgenconfig_getIP();
gchar* tgenconfig_getSOCKS();

#endif /* TGEN_CONFIG_H_ */
