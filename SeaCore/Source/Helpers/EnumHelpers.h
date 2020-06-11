#pragma once

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


#define ENUM_CONVERT(Enum) \
	inline std::underlying_type<Enum>::type Convert(Enum value) { return static_cast<std::underlying_type<Enum>::type>(value); } \
	inline Enum Convert(std::underlying_type<Enum>::type value) { return Enum(value); }
