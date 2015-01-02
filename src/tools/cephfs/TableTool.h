// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab
/*
 * Ceph - scalable distributed file system
 *
 * Copyright (C) 2015 John Spray <john.spray@redhat.com>
 *
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software
 * Foundation.  See file COPYING.
 */


#include "MDSUtility.h"

#include "include/rados/librados.hpp"


/**
 * Command line tool for debugging the backing store of
 * MDSTable instances.
 */
class TableTool : public MDSUtility
{
  private:
    mds_rank_t rank;

    // I/O handles
    librados::Rados rados;
    librados::IoCtx io;

    int _reset_session_table(mds_rank_t rank);
    int reset_session_table();

  public:
    void usage();
    TableTool() :
      rank(MDS_RANK_NONE) {}
    int main(std::vector<const char*> &argv);

};
