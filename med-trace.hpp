#pragma once
#include <eosiolib/crypto.h>
#include <eosiolib/eosio.hpp>
#include <eosiolib/privileged.hpp>
#include <string>

namespace eosio {

  class [[eosio::contract("eosio.drug")]] drug : public contract {

     public:

        using contract::contract;

	[[eosio::action]]
        void authen( name account);

	[[eosio::action]]
        void update( name account, capi_checksum256 _hash, std::string _name, std::string _location, uint64_t _status);

	[[eosio::action]]
        void check_status( name account, uint64_t _status );

        [[eosio::action]]
        void add( name account, const std::vector<char>& abi );

        struct [[eosio::table]] abi_hash {
           name              owner;
	   capi_checksum256  _hash;
   	   std::string 	     _name;
   	   std::string       _location;
   	   uint64_t	     _status;

           uint64_t primary_key()const { return owner.value; }

           EOSLIB_SERIALIZE( abi_hash, (owner)(_hash)(_name)(_status)(_location) )
        };

        typedef eosio::multi_index< "abihash"_n, abi_hash > abi_hash_table;
  };

} /// namespace eosio
