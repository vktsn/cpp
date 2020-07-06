#include "int_list_t.h"

int_list_t::int_list_t() {
    head = new node_t(0, nullptr, nullptr);
    tail = new node_t(0, nullptr, head);
    head->next = tail;
    list_size = 0;
}

int_list_t::node_t* int_list_t::get(int pos) const {
    if (pos <= list_size / 2) {
        node_t* current = head->next;
        while (pos > 0) {
            current = current->next;
            pos--;
        }

        return current;
    }
    else {
        node_t* current = tail;
        while (pos < list_size) {
            current = current->prev;
            pos++;
        }

        return current;
    }
}

int_list_t::int_list_t(const int_list_t& other) : int_list_t() {
    list_size = other.list_size;
    auto current = other.head->next;
    while (current != other.tail) {
        push_back(current->value);
        current = current->next;
    }
}

int_list_t::int_list_t(size_t count, int value) : int_list_t() {
    for (int i = 1; i < count; ++i) {
        push_back(value);
    }
}

void int_list_t::clear() {
    if (!empty()) {
        return;
    }
    node_t* pointer = head->next;
    node_t* next = pointer->next;
    for (int i = 0; i < size(); ++i) {
        delete pointer;
        pointer = next;
        next = pointer->next;
    }
    head->next = tail;
    tail->prev = head;
    list_size = 0;
}

int_list_t::~int_list_t() {
    clear();
    delete head;
    delete tail;
}

int_list_t& int_list_t::operator=(const int_list_t& other) {
    int_list_t current(other);
    swap(current);
    return *this;
}

int& int_list_t::operator[](size_t pos) {
    node_t* current = get(pos);
    return current->value;
}

const int& int_list_t::operator[](size_t pos) const {
    node_t* pointer = get(pos);
    return pointer->value;
}

int& int_list_t::back() {
    return tail->prev->value;
}

const int int_list_t::back() const {
    return tail->prev->value;
}

int& int_list_t::front() {
    return head->next->value;
}

const int int_list_t::front() const {
    return head->next->value;
}

size_t int_list_t::size() const {
    return list_size;
}

bool int_list_t::empty() const {
    return (list_size == 0);
}

void int_list_t::insert(size_t pos, int new_val) {
    node_t* current = get(pos);
    node_t* new_node = new node_t(new_val, current, current->prev);
    current->prev->next = new_node;
    current->prev = new_node;
    list_size++;
};

void int_list_t::push_front(int new_val) {
    insert(0, new_val);
};

void int_list_t::push_back(int new_val) {
    insert(list_size, new_val);
};

void int_list_t::erase(size_t pos) {
    node_t* current = get(pos);
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    list_size--;
};

void int_list_t::pop_front() {
    erase(0);
};

void int_list_t::pop_back() {
    erase(list_size - 1);
};

int_list_t int_list_t::splice(size_t start_pos, size_t count) {
    int_list_t result_list;
    node_t* current = get(start_pos);
    result_list.head->next = current;
    current->prev = result_list.head;
    node_t* end_1 = current->prev;

    for (int i = 0; i < count - 1; i++) {
        current = current->next;
    };

    result_list.tail->prev = current;
    current->next = result_list.tail;
    node_t* end_2 = current->next;

    end_1->next = end_2;
    end_2->prev = end_1;

    list_size -= count;
    result_list.list_size = count;
    return result_list;
};

int_list_t& int_list_t::merge(int_list_t& other) {
    if (!other.empty()) {
        tail->prev->next = other.head->next;
        other.head->next->prev = tail->prev;
        other.tail->prev->next = tail;
        tail->prev = other.tail->prev;

        other.head->next = other.tail;
        other.tail->prev = other.head;
        list_size += other.list_size;
        other.list_size = 0;
    };

    return *this;
};

void int_list_t::reverse() {
    if (!empty()) {
        node_t* current = head->next;
        node_t* next_node = current->next;
        while (next_node != tail) {
            std::swap(current->next, current->prev);
            current = next_node;
            next_node = current->next;
        }
        head->next->prev = head;
        tail->prev->next = tail;
        std::swap(head->next, tail->prev);
    }
}

void int_list_t::swap(int_list_t& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(list_size, other.list_size);
}

std::istream& operator>>(std::istream& stream, int_list_t& list) {
    int value = 0;
    list.clear();
    while (stream >> value) {
        list.push_back(value);
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const int_list_t& list) {
    auto current = list.head->next;
    while (current != list.tail) {
        stream << current->value << " ";
        current = current->next;
    }
    return stream;
}
