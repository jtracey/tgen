/*
 * See LICENSE for licensing information
 */

#ifndef TGEN_TRANSPORT_H_
#define TGEN_TRANSPORT_H_

#include "tgen.h"

typedef enum _TGenTransportProtocol {
    TGEN_PROTOCOL_NONE, TGEN_PROTOCOL_TCP, TGEN_PROTOCOL_UDP,
    TGEN_PROTOCOL_PIPE, TGEN_PROTOCOL_SOCKETPAIR,
} TGenTransportProtocol;

typedef struct _TGenTransport TGenTransport;

typedef void (*TGenTransport_notifyBytesFunc)(gpointer data, gsize bytesRead, gsize bytesWritten);

TGenTransport* tgentransport_newActive(TGenPeer* proxy, gchar* username, gchar* password, TGenPeer* peer,
        TGenTransport_notifyBytesFunc notify, gpointer data, GDestroyNotify destructData);
TGenTransport* tgentransport_newPassive(gint socketD, gint64 started, gint64 created, TGenPeer* peer,
        TGenTransport_notifyBytesFunc notify, gpointer data, GDestroyNotify destructData);

void tgentransport_ref(TGenTransport* transport);
void tgentransport_unref(TGenTransport* transport);

gssize tgentransport_write(TGenTransport* transport, gpointer buffer, gsize length);
gssize tgentransport_read(TGenTransport* transport, gpointer buffer, gsize length);

gint tgentransport_getDescriptor(TGenTransport* transport);
const gchar* tgentransport_toString(TGenTransport* transport);
gchar* tgentransport_getTimeStatusReport(TGenTransport* transport);

gboolean tgentransport_wantsEvents(TGenTransport* transport);
TGenEvent tgentransport_onEvent(TGenTransport* transport, TGenEvent events);

#endif /* TGEN_TRANSPORT_H_ */
