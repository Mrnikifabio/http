#ifndef LOCALCACHE_H
#define LOCALCACHE_H

#include <QtCore>

/**
 * @brief Not thread-safe
 */
class LocalCache {

public:
    static LocalCache *instance(const QString &name);
    static QString hash(const QString &s);

    void setMaxSeconds(uint value) { maxSeconds = value; }
    void setMaxSize(uint value) { maxSize = value; }
    bool isCached(const QString &key);
    QByteArray value(const QString &key) const;
    void insert(const QString &key, const QByteArray &value);

private:
    LocalCache(const QString &name);
    QString cachePath(const QString &key) const;
    qint64 expire();

    QString name;
    QString directory;
    uint maxSeconds;
    qint64 maxSize;
    qint64 size;
    bool expiring;

};

#endif // LOCALCACHE_H
