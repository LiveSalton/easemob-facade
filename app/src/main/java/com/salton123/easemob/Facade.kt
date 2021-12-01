package com.salton123.easemob

/**
 * Time:2021/11/30 4:08 下午
 * Author:
 * Description:
 */
object Facade {

    init {
        System.loadLibrary("easemob-facade")
    }

    /**
     * 创建账号
     * @param username 账号名
     * @param password 密码
     *
     */
    external fun createAccount(username: String, password: String)

    /**
     * 当前版本号
     * @return 当前版本号
     */
    external fun version(): String
}