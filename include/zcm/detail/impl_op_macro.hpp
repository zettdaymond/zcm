#pragma once

#define ZCM_IMPL_V2_BINOP(T, V, op) \
    ZCM_IMPL_V2_V2_BINOP(V, op) \
    ZCM_IMPL_V2_SC_BINOP(T, V, op) \
    ZCM_IMPL_SC_V2_BINOP(T, V, op) \

#define ZCM_IMPL_V2_COMPOUND_OP(T, V, op) \
    ZCM_IMPL_V2_COMPOUND_VEC_OP(V, op) \
    ZCM_IMPL_V2_COMPOUND_SC_OP(T, V, op)

// -----------------------------------------------------------------------------

#define ZCM_IMPL_V3_BINOP(T, V, op) \
    ZCM_IMPL_V3_V3_BINOP(V, op) \
    ZCM_IMPL_V3_SC_BINOP(T, V, op) \
    ZCM_IMPL_SC_V3_BINOP(T, V, op) \

#define ZCM_IMPL_V3_COMPOUND_OP(T, V, op) \
    ZCM_IMPL_V3_COMPOUND_VEC_OP(V, op) \
    ZCM_IMPL_V3_COMPOUND_SC_OP(T, V, op)

// -----------------------------------------------------------------------------

#define ZCM_IMPL_V4_BINOP(T, V, op) \
    ZCM_IMPL_V4_V4_BINOP(V, op) \
    ZCM_IMPL_V4_SC_BINOP(T, V, op) \
    ZCM_IMPL_SC_V4_BINOP(T, V, op) \

#define ZCM_IMPL_V4_COMPOUND_OP(T, V, op) \
    ZCM_IMPL_V4_COMPOUND_VEC_OP(V, op) \
    ZCM_IMPL_V4_COMPOUND_SC_OP(T, V, op)

// -----------------------------------------------------------------------------

#define ZCM_IMPL_V2_V2_BINOP(V, op) \
V operator op(V first, V second) noexcept { return { first._data[0] op second._data[0], first._data[1] op second._data[1] }; }

#define ZCM_IMPL_V2_SC_BINOP(T, V, op) \
V operator op(V vec, T scalar) noexcept { return { vec._data[0] op scalar, vec._data[1] op scalar }; }

#define ZCM_IMPL_SC_V2_BINOP(T, V, op) \
V operator op(T scalar, V vec) noexcept { return { scalar op vec._data[0], scalar op vec._data[1] }; }

#define ZCM_IMPL_V2_COMPOUND_VEC_OP(V, op) \
void V::operator op(V other) noexcept { _data[0] op other._data[0]; _data[1] op other._data[1]; }

#define ZCM_IMPL_V2_COMPOUND_SC_OP(T, V, op) \
void V::operator op(T scalar) noexcept { _data[0] op scalar; _data[1] op scalar; }

// -----------------------------------------------------------------------------

#define ZCM_IMPL_V3_V3_BINOP(V, op) \
V operator op(V first, V second) noexcept { return { first._data[0] op second._data[0], first._data[1] op second._data[1], first._data[2] op second._data[2]  }; }

#define ZCM_IMPL_V3_SC_BINOP(T, V, op) \
V operator op(V vec, T scalar) noexcept { return { vec._data[0] op scalar, vec._data[1] op scalar, vec._data[2] op scalar }; }

#define ZCM_IMPL_SC_V3_BINOP(T, V, op) \
V operator op(T scalar, V vec) noexcept { return { scalar op vec._data[0], scalar op vec._data[1], scalar op vec._data[2] }; }

#define ZCM_IMPL_V3_COMPOUND_VEC_OP(V, op) \
void V::operator op(V other) noexcept { _data[0] op other._data[0]; _data[1] op other._data[1]; _data[2] op other._data[2]; }

#define ZCM_IMPL_V3_COMPOUND_SC_OP(T, V, op) \
void V::operator op(T scalar) noexcept { _data[0] op scalar; _data[1] op scalar; _data[2] op scalar; }

// -----------------------------------------------------------------------------

#define ZCM_IMPL_V4_V4_BINOP(V, op) \
V operator op(V first, V second) noexcept { return { first._data[0] op second._data[0], first._data[1] op second._data[1], first._data[2] op second._data[2], first._data[3] op second._data[3] }; }

#define ZCM_IMPL_V4_SC_BINOP(T, V, op) \
V operator op(V vec, T scalar) noexcept { return { vec._data[0] op scalar, vec._data[1] op scalar, vec._data[2] op scalar, vec._data[3] op scalar }; }

#define ZCM_IMPL_SC_V4_BINOP(T, V, op) \
V operator op(T scalar, V vec) noexcept { return { scalar op vec._data[0], scalar op vec._data[1], scalar op vec._data[2], scalar op vec._data[3] }; }

#define ZCM_IMPL_V4_COMPOUND_VEC_OP(V, op) \
void V::operator op(V other) noexcept { _data[0] op other._data[0]; _data[1] op other._data[1]; _data[2] op other._data[2]; _data[3] op other._data[3];}

#define ZCM_IMPL_V4_COMPOUND_SC_OP(T, V, op) \
void V::operator op(T scalar) noexcept { _data[0] op scalar; _data[1] op scalar; _data[2] op scalar; _data[3] op scalar; }
