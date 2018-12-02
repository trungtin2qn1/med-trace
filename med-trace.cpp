#pragma once
#include <eosiolib/crypto.h>
#include <eosiolib/eosio.hpp>
#include <eosiolib/privileged.hpp>
#include <string>
#include "med-trace.hpp"

namespace eosio {

	[[eosio::action]]
        void drug::authen( name account) {
           require_auth( account );
        }

	[[eosio::action]]
        void drug::update( name account, capi_checksum256 _hash, std::string _name, std::string _location, uint64_t _status) {
           abi_hash_table table(_self, _self.value);
           auto itr = table.find( account.value );
           if( itr != table.end() ) {
              table.emplace( account, [&]( auto& row ) {
                 row.owner = account;
		 //sha256( const_cast<char*>(abi.data()), abi.size(), &row._hash );
		 row._name = _name;
		 row._location = _location;
		 row._status = _status;
              });
           }
        }

	[[eosio::action]]
        void drug::check_status( name account, uint64_t _status ) {
           switch(_status) {
	   case 0:
		// unsold
		break;
	   case 1:
		// sold
		break;
	   case 2:
		// Oudated
		break;
	   case 3:
		// Defect
		break;
	   default:
		break;
	   }	
        }

        [[eosio::action]]
        void drug::add( name account, const std::vector<char>& abi ) {
           abi_hash_table table(_self, _self.value);
           auto itr = table.find( account.value );
           if( itr == table.end() ) {
              table.emplace( account, [&]( auto& row ) {
                 row.owner = account;
		//sha256( const_cast<char*>(abi.data()), abi.size(), &row._hash );
		 row._name = "a";
		 row._location = "LA";
		 row._status = 0;
              });
           }
        }

} /// namespace eosio
