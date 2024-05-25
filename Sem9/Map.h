#pragma once
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <tuple>

template<typename K, typename V>
struct Entry {
    K key;
    V value;
    int index;

    Entry() : key(K()), value(V()), index(-1) {}
    Entry(K k, V v, int idx) : key(k), value(v), index(idx) {}
};

template<typename K, typename V>
class Map {
private:
    Entry<K, V>* entries;
    int entry_count;
    int capacity;

    void resize() {
        capacity *= 2;
        Entry<K, V>* new_entries = new Entry<K, V>[capacity];
        for (int i = 0; i < entry_count; ++i) {
            new_entries[i] = entries[i];
        }
        delete[] entries;
        entries = new_entries;
    }

public:
    Map() : entry_count(0), capacity(50) {
        entries = new Entry<K, V>[capacity];
    }

    ~Map() {
        delete[] entries;
    }

    V& operator[](const K& key) {
        for (int i = 0; i < entry_count; ++i) {
            if (entries[i].key == key) {
                return entries[i].value;
            }
        }
        if (entry_count == capacity) {
            resize();
        }
        entries[entry_count] = Entry<K, V>(key, V(), entry_count);
        return entries[entry_count++].value;
    }

    void Set(const K& key, const V& value) {
        for (int i = 0; i < entry_count; ++i) {
            if (entries[i].key == key) {
                entries[i].value = value;
                return;
            }
        }
        if (entry_count == capacity) {
            resize();
        }
        entries[entry_count] = Entry<K, V>(key, value, entry_count);
        entry_count++;
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < entry_count; ++i) {
            if (entries[i].key == key) {
                value = entries[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return entry_count;
    }

    void Clear() {
        delete[] entries;
        entry_count = 0;
        capacity = 50;
        entries = new Entry<K, V>[capacity];
    }

    bool Delete(const K& key) {
        for (int i = 0; i < entry_count; ++i) {
            if (entries[i].key == key) {
                for (int j = i; j < entry_count - 1; ++j) {
                    entries[j] = entries[j + 1];
                    entries[j].index = j;
                }
                entry_count--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& other_map) const {
        for (int i = 0; i < other_map.entry_count; ++i) {
            bool found = false;
            for (int j = 0; j < entry_count; ++j) {
                if (entries[j].key == other_map.entries[i].key) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    class Iterator {
    private:
        Entry<K, V>* current;
    public:
        Iterator(Entry<K, V>* start) : current(start) {}
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
        void operator++() {
            ++current;
        }
        std::tuple<K, V, int> operator*() const {
            return std::make_tuple(current->key, current->value, current->index);
        }
    };

    Iterator begin() const {
        return Iterator(entries);
    }

    Iterator end() const {
        return Iterator(entries + entry_count);
    }
};

#endif // MAP_H
