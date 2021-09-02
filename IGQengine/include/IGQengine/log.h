#pragma once

#include "spdlog/spdlog.h"

#define IGQ_DEFAULT_LOGGER_NAME "IGQlogger"

#if defined(IGQ_PLATFORM_WINDOWS)
#define IGQ_BREAK __debugbreak();
#elif defined(IGQ_PLATFORM_MAC)
#define IGQ_BREAK __builtin_debugtrap();
#else
#define IGQ_BREAK __builtin_trap();
#endif

#ifndef IGQ_CONFIG_RELEASE

#define IGQ_TRACE(...)  if(spdlog::get(IGQ_DEFAULT_LOGGER_NAME) != nullptr){spdlog::get(IGQ_DEFAULT_LOGGER_NAME)->trace(__VA_ARGS__);}
#define IGQ_DEBUG(...)  if(spdlog::get(IGQ_DEFAULT_LOGGER_NAME) != nullptr){spdlog::get(IGQ_DEFAULT_LOGGER_NAME)->debug(__VA_ARGS__);}
#define IGQ_INFO(...)  if(spdlog::get(IGQ_DEFAULT_LOGGER_NAME) != nullptr){spdlog::get(IGQ_DEFAULT_LOGGER_NAME)->info(__VA_ARGS__);}
#define IGQ_WARN(...)  if(spdlog::get(IGQ_DEFAULT_LOGGER_NAME) != nullptr){spdlog::get(IGQ_DEFAULT_LOGGER_NAME)->warn(__VA_ARGS__);}
#define IGQ_ERROR(...)  if(spdlog::get(IGQ_DEFAULT_LOGGER_NAME) != nullptr){spdlog::get(IGQ_DEFAULT_LOGGER_NAME)->error(__VA_ARGS__);}
#define IGQ_FATAL(...)  if(spdlog::get(IGQ_DEFAULT_LOGGER_NAME) != nullptr){spdlog::get(IGQ_DEFAULT_LOGGER_NAME)->critical(__VA_ARGS__);}
#define IGQ_ASSERT(x, msg) if((x)) {} else { IGQ_FATAL("ASSERT - {}\n\t{}\n\tint file: {}\n\ton line: {}",#x, msg, __FILE__, __LINE__); IGQ_BREAK}

#else

#define IGQ_TRACE(...)  (void)0
#define IGQ_DEBUG(...)  (void)0
#define IGQ_INFO(...)  (void)0
#define IGQ_WARN(...)  (void)0
#define IGQ_ERROR(...)  (void)0
#define IGQ_FATAL(...)  (void)0

#endif
