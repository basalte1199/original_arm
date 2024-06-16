// Copyright (c) 2023 OUXT Polaris
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ORIGINAL_ARM__VISIBILITY_CONTROL_H_
#define ORIGINAL_ARM__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define ORIGINAL_ARM_EXPORT __attribute__((dllexport))
#define ORIGINAL_ARM_IMPORT __attribute__((dllimport))
#else
#define ORIGINAL_ARM_EXPORT __declspec(dllexport)
#define ORIGINAL_ARM_IMPORT __declspec(dllimport)
#endif
#ifdef ORIGINAL_ARM_BUILDING_LIBRARY
#define ORIGINAL_ARM_PUBLIC ORIGINAL_ARM_EXPORT
#else
#define ORIGINAL_ARM_PUBLIC ORIGINAL_ARM_IMPORT
#endif
#define ORIGINAL_ARM_PUBLIC_TYPE ORIGINAL_ARM_PUBLIC
#define ORIGINAL_ARM_LOCAL
#else
#define ORIGINAL_ARM_EXPORT __attribute__((visibility("default")))
#define ORIGINAL_ARM_IMPORT
#if __GNUC__ >= 4
#define ORIGINAL_ARM_PUBLIC __attribute__((visibility("default")))
#define ORIGINAL_ARM_LOCAL __attribute__((visibility("hidden")))
#else
#define ORIGINAL_ARM_PUBLIC
#define ORIGINAL_ARM_LOCAL
#endif
#define ORIGINAL_ARM_PUBLIC_TYPE
#endif

#endif  // TUTORIAL__VISIBILITY_CONTROL_H_