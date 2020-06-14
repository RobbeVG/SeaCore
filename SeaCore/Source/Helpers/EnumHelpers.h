#pragma once
#include <type_traits>

// Stolen from UNREAL ENGINE MACRO FOR FLAG ENUMS
// Slightly modified
// Defines all bitwise operators for enum classes so it can be (mostly) used as a regular flags enum

/*
 * Defines flag operators for an enum.
 * If enum inside class use : CLASSNAME::ENUMNAME
 * Place MACRO outside class
 */
#define ENUM_FLAGS(Enum) \
		inline           Enum& operator|=(Enum& lhs, Enum rhs) { return lhs = static_cast<Enum>(static_cast<std::underlying_type<Enum>::type>(lhs) | static_cast<std::underlying_type<Enum>::type>(rhs)); } \
		inline           Enum& operator&=(Enum& lhs, Enum rhs) { return lhs = static_cast<Enum>(static_cast<std::underlying_type<Enum>::type>(lhs) & static_cast<std::underlying_type<Enum>::type>(rhs)); } \
		inline           Enum& operator^=(Enum& lhs, Enum rhs) { return lhs = static_cast<Enum>(static_cast<std::underlying_type<Enum>::type>(lhs) ^ static_cast<std::underlying_type<Enum>::type>(rhs)); } \
		inline constexpr Enum  operator| (Enum  lhs, Enum rhs) { return static_cast<Enum>(static_cast<std::underlying_type<Enum>::type>(lhs) | static_cast<std::underlying_type<Enum>::type>(rhs)); } \
		inline constexpr Enum  operator& (Enum  lhs, Enum rhs) { return static_cast<Enum>(static_cast<std::underlying_type<Enum>::type>(lhs) & static_cast<std::underlying_type<Enum>::type>(rhs)); } \
		inline constexpr Enum  operator^ (Enum  lhs, Enum rhs) { return static_cast<Enum>(static_cast<std::underlying_type<Enum>::type>(lhs) ^ static_cast<std::underlying_type<Enum>::type>(rhs)); } \
		inline constexpr bool  operator! (Enum  value) { return !static_cast<std::underlying_type<Enum>::type>(value); } \
		inline constexpr Enum  operator~ (Enum  value) { return static_cast<Enum>(~static_cast<std::underlying_type<Enum>::type>(value)); }



template< typename Enum >
constexpr typename std::underlying_type<Enum>::type ConvertEnum(Enum value) noexcept { return static_cast<typename std::underlying_type<Enum>::type>(value); };

template< typename Enum >
constexpr Enum ConvertEnum(typename std::underlying_type<Enum>::type value) noexcept { return Enum(value); }
