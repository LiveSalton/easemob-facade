package com.salton123.easemob

/**
 * Time:2021/11/30 4:08 下午
 * Author:
 * Description:
 */
object Facade {
    external fun createAccount(username: String, password: String)
    external fun version(): String
}