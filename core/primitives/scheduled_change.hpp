/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef KAGOME_CORE_PRIMITIVES_SCHEDULED_CHANGE
#define KAGOME_CORE_PRIMITIVES_SCHEDULED_CHANGE

#include "primitives/authority.hpp"
#include "primitives/common.hpp"

namespace kagome::primitives {
  struct DelayInChain {
    uint32_t subchain_lenght = 0;
  };

  struct AuthorityListChange {
    AuthorityList authorities{};
    uint32_t subchain_lenght = 0;
  };

  struct ScheduledChange : public AuthorityListChange {};
  struct ForcedChange : public AuthorityListChange {};
  struct OnDisabled {
    uint64_t authority_index = 0;
  };
  struct Pause : public DelayInChain {};
  struct Resume : public DelayInChain {};

  template <class Stream>
  Stream &operator<<(Stream &s, const DelayInChain &delay) {
    return s << delay.subchain_lenght;
  }

  template <class Stream>
  Stream &operator>>(Stream &s, DelayInChain &delay) {
    return s >> delay.subchain_lenght;
  }

  template <class Stream>
  Stream &operator<<(Stream &s, const OnDisabled &target) {
    return s << target.authority_index;
  }

  template <class Stream>
  Stream &operator>>(Stream &s, OnDisabled &target) {
    return s >> target.authority_index;
  }

  template <class Stream>
  Stream &operator<<(Stream &s, const AuthorityListChange &alc) {
    return s << alc.authorities << alc.subchain_lenght;
  }

  template <class Stream>
  Stream &operator>>(Stream &s, AuthorityListChange &alc) {
    return s >> alc.authorities >> alc.subchain_lenght;
  }
}  // namespace kagome::primitives

#endif  // KAGOME_CORE_PRIMITIVES_SCHEDULED_CHANGE
